/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:54:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 19:51:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "solution.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>

bool	is_solution_inside_range(t_solution *solu, const t_range *range);

static void	init_solution_context(
	t_solution *solu,
	const t_cylinder *self,
	const t_ray *ray);
static t_vec3	calc_cylinder_coeff(
	const t_vec3 *ray_direct,
	const t_vec3 *center_to_ray_origin,
	const t_vec3 *cylinder_dir,
	double radius);
static void	set_cy_solu_info(
	t_cy_solu *cy_solu,
	const t_cylinder *self,
	const t_ray *ray);
static bool	is_in_range_of_height(const double tmp_height, const double height);
static void	assign_cylinder_hrec(
	const t_cylinder *self,
	const t_ray *ray,
	t_hrec *hrec,
	const t_cy_solu *cy_solu);
static t_vec3	calc_cylinder_normal(
	const t_cylinder *self,
	const t_vec3 *point,
	double tmp_height);
static t_vec2	construct_cylinder_uv(
	const t_vec3 *center_to_point,
	const t_vec3 *direct,
	double tmp_height,
	double height);

bool	hit_cylinder(
	const void *s,
	const t_ray *ray,
	t_hrec *hrec,
	t_range *range)
{
	const t_cylinder	*self = s;
	t_cy_solu			cy_solu;

	init_solution_context(&cy_solu.solu, self, ray);
	if (!is_solution_inside_range(&cy_solu.solu, range))
		return (false);
	set_cy_solu_info(&cy_solu, self, ray);
	if (!is_in_range_of_height(cy_solu.tmp_height, self->height))
		return (false);
	assign_cylinder_hrec(self, ray, hrec, &cy_solu);
	return (true);
}

static void	assign_cylinder_hrec(
	const t_cylinder *self,
	const t_ray *ray,
	t_hrec *hrec,
	const t_cy_solu *cy_solu)
{
	hrec->mat_ptr = self->hitter.mat_ptr;
	hrec->param_t = cy_solu->solu.solution;
	hrec->point = cy_solu->point;
	hrec->ray_in = *ray;
	hrec->normal = calc_cylinder_normal(self, &hrec->point, cy_solu->tmp_height);
	hrec->map = construct_cylinder_uv(
			&cy_solu->center_to_point,
			&self->direct,
			cy_solu->tmp_height,
			self->height);
}

static t_vec3	calc_cylinder_normal(
	const t_cylinder *self,
	const t_vec3 *point,
	double tmp_height)
{
	t_point3	point_on_axis;

	point_on_axis = add_vec3(self->center,scal_mul_vec3(self->direct, tmp_height));
	return (scal_div_vec3(
				sub_vec3(*point, point_on_axis),
				self->radius));
}

static t_vec2	construct_cylinder_uv(
	const t_vec3 *center_to_point,
	const t_vec3 *direct,
	double tmp_height,
	double height)
{
	const t_onb		onb = construct_onb(*direct);
	const double	theta = atan2(
		dot(*center_to_point, onb.v[0]),
		dot(*center_to_point, onb.v[1]));

	return (construct_vec2(
				1.0 - (theta / (2.0 * M_PI) + 0.5),
				tmp_height / height));
}

static bool	is_in_range_of_height(const double tmp_height, const double height)
{
	return (0 < tmp_height && tmp_height < height);
}

static void	set_cy_solu_info(
				t_cy_solu *cy_solu,
				const t_cylinder *self,
				const t_ray *ray)
{
	cy_solu->point = at_ray(ray, cy_solu->solu.solution);
	cy_solu->center_to_point = sub_vec3(cy_solu->point, self->center);
	cy_solu->tmp_height = dot(cy_solu->center_to_point, self->direct);
}

static void	init_solution_context(
	t_solution *solu,
	const t_cylinder *self,
	const t_ray *ray)
{
	const t_vec3	center_to_ray_origin = sub_vec3(ray->origin, self->center);

	solu->coeff = calc_cylinder_coeff(
		&ray->direct,
		&center_to_ray_origin,
		&self->direct,
		self->radius);
	solu->discriminant = calc_discriminant(solu);
}

static t_vec3	calc_cylinder_coeff(
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
