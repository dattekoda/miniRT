/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_phong_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:39:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/10 20:57:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include "world.h"
#include "material.h"
#include "vec_utils.h"
#include <math.h>

static t_color	calc_phong_color(const t_world *world, const t_hrec *hrec);
t_color			calc_color_from_light_list(const t_list *light_list,
			const t_color *reflectance, const t_hrec *hrec);

t_color	compute_phong_color(
			const t_ray *ray,
			const t_world *world)
{
	t_range	range;
	t_hrec	hrec;

	range = construct_vec2(HIT_T_MIN, INFINITY);
	if (world->object_tree
		|| world->object_tree->hit(world->object_tree, ray, &hrec, &range))
		return (calc_phong_color(&world, &hrec));
	return (world->ambient);
}

static t_color	calc_phong_color(const t_world *world, const t_hrec *hrec)
{
	const t_color	reflectance = hrec->mat_ptr->texture_ptr
		->calc_texture_value(hrec->mat_ptr->texture_ptr, hrec);
	t_color	ambient;
	t_color	color_from_light;

	ambient = calc_ambient(&reflectance, &world->ambient);
	color_from_light = calc_color_from_light_list(
				world->light_list, &reflectance, hrec);
	return (add_vec3(ambient, color_from_light));
}

static t_color	calc_ambient(const t_color *reflectance,
					const t_color *ambient)
{
	const t_color	ka = scal_mul_vec3(*reflectance, PHONG_AMBIENT_COEFF);

	return (mul_vec3(ka, *ambient));
}
