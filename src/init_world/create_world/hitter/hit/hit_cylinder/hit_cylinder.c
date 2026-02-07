/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 06:26:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 06:44:24 by ikawamuk         ###   ########.fr       */
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
static bool		is_inside_height(
					const t_cylinder *self,
					const t_ray *ray,
					t_hrec *hrec,
					t_solution *solu);
void			assign_cylinder_hrec(
					const t_cylinder *self,
					const t_ray *ray,
					t_hrec *hrec,
					const t_solution *solu);

bool	hit_cylinder(
			const void *s,
			const t_ray *ray,
			t_hrec *hrec,
			t_range *range)
{
	const t_cylinder	*self;
	t_solution			solu;

	self = s;
	init_solution_context(&solu, self, ray);
	if (!is_solution_in_range(&solu, range))
		return (false);
	if (!is_inside_height(self, ray, hrec, &solu))
		return (false);
	range->e[1] = solu.solution;
	assign_cylinder_hrec(self, ray, hrec, &solu);
	return (true);
}

static void	init_solution_context(
		t_solution *solu, const t_cylinder *self, const t_ray *ray)
{
	t_solution		solu;
	const t_vec3	center_to_ray_origin = sub_vec3(ray->origin, self->center);

	solu->coeff = calc_coeff(
			&ray->direct, &center_to_ray_origin, &self->direct, self->radius);
	solu->discriminant = calc_discriminant(&solu);
	return ;
}


/*
@brief check if point is inside height and assign hrec
*/
static bool	is_inside_height(
			const t_cylinder *self,
			const t_ray *ray,
			t_hrec *hrec,
			t_solution *solu)
{
	t_vec3		center_to_point;
	double		tmp_height;

	solu->point = at_ray(ray, solu->solution);
	center_to_point = sub_vec3(solu->point, self->center);
	tmp_height = dot(center_to_point, self->direct);
	if (tmp_height < 0 || tmp_height < self->height)
		return (false);
	return (true);
}

static t_vec3	calc_coeff(
					const t_vec3 *ray_direct,
					const t_vec3 *center_to_ray_origin,
					const t_vec3 *cylinder_axis,
					double radius)
{
	double	ray_dir_len_sq;
	double	ctoori_len_sq;
	double	ray_dot_cyaxis;
	double	ax_dot_cto_ori;
	double	ctoori_dot_ray;

	ray_dir_len_sq = length_squared_vec3(*ray_direct);
	ctoori_len_sq = length_squared_vec3(*center_to_ray_origin);
	ray_dot_cyaxis = dot(*ray_direct, *cylinder_axis);
	ax_dot_cto_ori = dot(*cylinder_axis, *center_to_ray_origin);
	ctoori_dot_ray = dot(*center_to_ray_origin, *ray_direct);
	return (construct_vec3(
			ray_dir_len_sq - pow(ray_dot_cyaxis, 2),
			ctoori_dot_ray - ray_dot_cyaxis * ax_dot_cto_ori,
			ctoori_len_sq - pow(ax_dot_cto_ori, 2) - pow(radius, 2)));
}
