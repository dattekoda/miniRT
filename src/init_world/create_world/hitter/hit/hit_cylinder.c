/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 06:26:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 15:29:19 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "solution.h"
#include "vec_utils.h"

static t_vec3	calc_coeff(
					const t_vec3 *ray_direct,
					const t_vec3 *center_to_ray_origin,
					const t_vec3 *cylinder_axis,
					double radius);

bool	hit_cylinder(
	const void *s, const t_ray *ray, t_hrec *hrec, t_range *range)
{
	const t_cylinder	*self;
	t_solution			solu;

	self = s;
	solu = init_solution_context(self, ray);
	if (is_solution_in_range(&solu, range))
		assign_sphere_hrec(self, ray, hrec, solu.solution);
	return (false);
}

static t_solution	init_solution_context(
		const t_cylinder *self, const t_ray *ray)
{
	t_solution	solu;
	t_vec3		center_to_ray_origin;
	// t_vec3		abc;

	ft_bzero(&solu, sizeof(t_solution));
	center_to_ray_origin = sub_vec3(ray->origin, self->center);
	solu.coeff = calc_coeff(
			&ray->direct, &center_to_ray_origin, &self->direct, self->radius);
	// abc = calc_abc(
	// 		&ray->direct, &center_to_ray_origin, &self->direct, self->radius);
	// solu.a = abc.e[0];
	// solu.b = abc.e[1];
	// solu.c = abc.e[2];
	solu.discriminant = calc_discriminant(&solu);
	return (solu);
}

static t_vec3	calc_coeff(
					const t_vec3 *ray_direct,
					const t_vec3 *center_to_ray_origin,
					const t_vec3 *cylinder_axis,
					double radius)
{
	double	ray_dir_len_sq;
	double	cto_ori_len_sq;
	double	ray_dot_cyaxis;
	double	ax_dot_cto_ori;
	double	cto_ori_dot_ray;

	ray_dir_len_sq = length_squared_vec3(*ray_direct);
	cto_ori_len_sq = length_squared_vec3(*center_to_ray_origin);
	ray_dot_cyaxis = dot(*ray_direct, *cylinder_axis);
	ax_dot_cto_ori = dot(*cylinder_axis, *center_to_ray_origin);
	cto_ori_dot_ray = dot(*center_to_ray_origin, *ray_direct);
	return (construct_vec3(
			ray_dir_len_sq - pow(ray_dot_cyaxis, 2),
			cto_ori_dot_ray - ray_dot_cyaxis * ax_dot_cto_ori,
			cto_ori_len_sq - pow(ax_dot_cto_ori, 2) - pow(radius, 2)));
}
