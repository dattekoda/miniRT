/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 06:26:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 16:53:27 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "solution.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>

static t_vec3	calc_coeff(
					const t_vec3 *ray_direct,
					const t_vec3 *center_to_ray_origin,
					const t_vec3 *cylinder_axis,
					double radius);
static void		init_solution_context(
					t_solution *solu,
					const t_cylinder *self,
					const t_ray *ray);
bool			validate_height_and_assign(
					const t_cylinder *self,
					const t_ray *ray,
					t_hrec *hrec,
					t_solution *solu);

#include <stdio.h>

bool	hit_cylinder(
			const void *s,
			const t_ray *ray,
			t_hrec *hrec,
			t_range *range)
{
	const t_cylinder	*self = s;
	t_solution			solu;

	init_solution_context(&solu, self, ray);
	if (!is_solution_inside_range(&solu, range))
		return (false);
	if (!validate_height_and_assign(self, ray, hrec, &solu))
		return (false);
	range->e[1] = solu.solution;
	return (true);
}

static void	init_solution_context(
		t_solution *solu,
		const t_cylinder *self,
		const t_ray *ray)
{
	const t_vec3	center_to_ray_origin = sub_vec3(ray->origin, self->center);

	solu->coeff = calc_coeff(
			&ray->direct,
			&center_to_ray_origin,
			&self->direct,
			self->radius);
	solu->discriminant = calc_discriminant(solu);
	return ;
}

static t_vec3	calc_coeff(
					const t_vec3 *ray_direct,
					const t_vec3 *center_to_ray_origin,
					const t_vec3 *cylinder_dir,
					double radius)
{
	const double	len_sq_ray_dir
		= length_squared_vec3(*ray_direct);
	const double	len_sq_c_to_ro
		= length_squared_vec3(*center_to_ray_origin);
	const double	dot_ray_dir__cy_dir
		= dot(*ray_direct, *cylinder_dir);
	const double	dot_cy_dir__c_to_ro
		= dot(*cylinder_dir, *center_to_ray_origin);
	const double	dot_c_to_ro__ray_dir
		= dot(*center_to_ray_origin, *ray_direct);

	return (construct_vec3(
			len_sq_ray_dir - pow(dot_ray_dir__cy_dir, 2),
			dot_c_to_ro__ray_dir - dot_ray_dir__cy_dir * dot_cy_dir__c_to_ro,
			len_sq_c_to_ro - pow(dot_cy_dir__c_to_ro, 2) - pow(radius, 2)));
}
