/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color_from_light_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:05:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/11 15:50:29 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "material.h"
#include "rt_define.h"
#include "ray.h"
#include "hitter.h"
#include "vec_utils.h"
#include "libft.h"
#include <math.h>

static t_color	calc_color_from_light(
					const t_hitter *light,
					const t_world *world,
					const t_color *kd,
					const t_hrec *hrec);
static bool		is_in_shadow(
					const t_world *world,
					const t_point3 *point,
					const t_vec3 *normalized_light_direct,
					double light_length);
static t_color	calc_specular(
					const t_hrec *hrec,
					const t_vec3 *light_direct,
					const t_color *light_color);
static t_color	calc_diffuse(
					const t_color *kd,
					const t_hrec *hrec,
					const t_vec3 *light_direct,
					const t_color *light_color);

t_color	calc_color_from_light_list(
			const t_world *world,
			const t_color *reflectance,
			const t_hrec *hrec)
{
	const t_color	kd = mul_vec3(
		*reflectance,
		construct_vec3(
			R_PHONG_DIFFUSE_COEFF,
			G_PHONG_DIFFUSE_COEFF,
			B_PHONG_DIFFUSE_COEFF));
	t_color	accumulate;
	t_list	*light_list;

	ft_bzero(&accumulate, sizeof(t_color));
	light_list = world->light_list;
	while (light_list)
	{
		accumulate = add_vec3(accumulate,
				calc_color_from_light(light_list->content, world, &kd, hrec));
		light_list = light_list->next;
	}
	return (accumulate);
}

static t_color	calc_color_from_light(
					const t_hitter *light,
					const t_world *world,
					const t_color *kd,
					const t_hrec *hrec)
{
	t_color			diffuse;
	t_color			specular;
	t_srec			tmp_srec;
	const t_vec3	light_direct
		= sub_vec3(light->aabb.centroid, hrec->point);
	const t_vec3	normalized_light_direct
		= normalize(light_direct);

	if (is_in_shadow(
			world,
			&hrec->point,
			&normalized_light_direct,
			length_vec3(light_direct)))
		return (constant_vec3(0.0));
	light->mat_ptr->scatter(light->mat_ptr, world, hrec, &tmp_srec);
	diffuse = calc_diffuse(kd, hrec, &light_direct, &tmp_srec.attenuation);
	specular = calc_specular(hrec, &light_direct, &tmp_srec.attenuation);
	return (add_vec3(diffuse, specular));
}

static bool	is_in_shadow(
			const t_world *world,
			const t_point3 *point,
			const t_vec3 *normalized_light_direct,
			double light_length)
{
	const t_ray		to_light = construct_ray(*point, *normalized_light_direct);
	t_range			range;
	t_hrec			tmp_rec;

	range = construct_vec2(HIT_T_MIN, light_length);
	return (world->object_tree->hit(
				world->object_tree, &to_light, &tmp_rec, &range));
}

static t_color	calc_specular(
			const t_hrec *hrec,
			const t_vec3 *light_direct,
			const t_color *light_color)
{
	const t_color	ks = construct_vec3(
						R_PHONG_SPECULAR_COEFF,
						G_PHONG_SPECULAR_COEFF,
						B_PHONG_SPECULAR_COEFF);
	const t_vec3	reflect_vec = reflect();
	const t_vec3	point_to_camera = normalize(
				negative_vec3(hrec->ray_in.direct));

	return (mul_vec3(*light_color,
			scal_mul_vec3(ks, pow(
					fmax(0, dot(reflect_vec, point_to_camera)), SHININESS))));
}

/*
@brief light_in_color * kd * max((L dot N), 0) 
*/
static t_color	calc_diffuse(
			const t_color *kd,
			const t_hrec *hrec,
			const t_vec3 *light_direct,
			const t_color *light_color)
{
	return (mul_vec3(*light_color,
			scal_mul_vec3(*kd, fmax(0, dot(*light_direct, hrec->normal)))));
}
