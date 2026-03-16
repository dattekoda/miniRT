/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_phong_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:39:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define_bonus.h"
#include "world_bonus.h"
#include "material_bonus.h"
#include "vec_utils_bonus.h"
#include <math.h>

t_color			calc_color_from_light_list(
					const t_world *world,
					const t_color *reflectance,
					const t_hrec *hrec);
static t_color	calc_phong_color(const t_world *world, t_hrec *hrec);
static t_color	calc_ambient(const t_color *reflectance,
					const t_color *ambient);

t_color	compute_phong_color(
			const t_ray *ray,
			const t_world *world)
{
	t_range	range;
	t_hrec	hrec;

	range = construct_vec2(HIT_T_MIN, INFINITY);
	if (world->object_tree
		&& world->object_tree->hit(world->object_tree, ray, &hrec, &range))
		return (calc_phong_color(world, &hrec));
	return (world->ambient_light);
}

static t_color	calc_phong_color(const t_world *world, t_hrec *hrec)
{
	const t_color	reflectance = hrec->mat_ptr->texture_ptr
		->calc_texture_value(hrec->mat_ptr->texture_ptr, hrec);
	const t_color	calculated_ambient
		= calc_ambient(&reflectance, &world->ambient_light);
	const t_color	color_from_light
		= calc_color_from_light_list(world, &reflectance, hrec);

	return (add_vec3(calculated_ambient, color_from_light));
}

static t_color	calc_ambient(const t_color *reflectance,
					const t_color *ambient)
{
	const t_color	ka
		= mul_vec3(*reflectance,
			construct_vec3(
				R_PHONG_AMBIENT_COEFF,
				G_PHONG_AMBIENT_COEFF,
				B_PHONG_AMBIENT_COEFF));

	return (mul_vec3(ka, *ambient));
}
