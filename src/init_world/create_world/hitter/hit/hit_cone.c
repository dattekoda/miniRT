/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:57:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/04 13:03:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "solution.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>

static void			init_solution_context(
						t_solution *solu,
						const t_cone *self,
						const t_ray *ray);
static t_vec3		calc_coeff(
						const t_vec3 *ray_dir,
						const t_cone *self,
						const t_vec3 *apex_to_ray_origin);
static void			assign_cone_hrec(
						const t_cone *self,
						const t_ray *ray,
						t_hrec *hrec,
						double solution);
static t_vec2		construct_cone_uv(const t_cone *self, const t_vec3 *cp);

bool	hit_cone(
	const void *s,
	const t_ray *ray,
	t_hrec *hrec,
	t_range *range)
{
	const t_cone	*self;
	t_solution		solu;

	self = s;
	init_solution_context(&solu, self, ray);
	if (!is_solution_inside_range(&solu, range))
		return (false);
	assign_cone_hrec(self, ray, hrec, solu.solution);
	range->e[1] = hrec->param_t;
	return (true);
}

static void	init_solution_context(
				t_solution *solu,
				const t_cone *self,
				const t_ray *ray)
{
	const t_vec3	apex_to_ray_origin = sub_vec3(ray->origin, self->apex);

	solu->coeff = calc_coeff(
			&ray->direct,
			self,
			&apex_to_ray_origin);
	solu->discriminant = calc_discriminant(solu);
	return ;
}

// Because |cone_dir| == 1
// dot((Point - Apex), cone_dir)^2 = |Point - Apex|^2 * cos_half_angle^2
// dot((Origin + ray_dir * t - Apex), cone_dir)^2
// 	= |Origin + ray_dir * t - Apex|^2 * cos_half_angle^2
// dot((apex_to_ray_origin + ray_dir * t), cone_dir)^2
// 	= |apex_to_ray_origin + ray_dir * t|^2 * cos_half_angle^2
// LHS = (dot(apex_to_ray_origin, cone_dir) + dot(ray_dir, cone_dir) * t)^2
// LHS = dot(ray_dir, cone_dir)^2 * t^2
// \+ 2 * dot(ray_dir, cone_dir) * dot(apex_to_ray_origin, cone_dir) * t
// \+ dot(apex_to_ray_origin, cone_dir)^2
// RHS = |ray_dir|^2 * cos_half_angle^2 * t^2
// \+ 2 * dot(apex_to_ray_origin, ray_dir) * cos_half_angle^2 * t
// \+ |apex_to_ray_origin|^2 * cos_half_angle^2
// coeff: LHS - RHS = 0
// you can ignore '2 *' of the 't' s coeff defined as e[1]
static t_vec3	calc_coeff(
	const t_vec3 *ray_dir,
	const t_cone *self,
	const t_vec3 *apex_to_ray_origin)
{
	const double	dot_rdir__cdir
		= dot(*ray_dir, self->direct);
	const double	dot_ap_to_ro__cdir
		= dot(*apex_to_ray_origin, self->direct);
	const double	dot_rdir__ap_to_ro
		= dot(*ray_dir, *apex_to_ray_origin);

	return (construct_vec3(
		dot_rdir__cdir * dot_rdir__cdir
			- length_squared_vec3(*ray_dir) * self->cos_half_angle_sq,
		dot_rdir__cdir * dot_ap_to_ro__cdir
			- dot_rdir__ap_to_ro * self->cos_half_angle_sq,
		dot_ap_to_ro__cdir * dot_ap_to_ro__cdir
			- length_squared_vec3(*apex_to_ray_origin)
			* self->cos_half_angle_sq));
}

static void	assign_cone_hrec(
				const t_cone *self,
				const t_ray *ray,
				t_hrec *hrec,
				double solution)
{
	t_vec3	apex_to_point;

	hrec->ray_in = *ray;
	hrec->param_t = solution;
	hrec->point = at_ray(ray, hrec->param_t);
	apex_to_point = sub_vec3(hrec->point, self->apex);
	hrec->normal = normalize(
					sub_vec3(
						apex_to_point,
						scal_mul_vec3(
							self->direct,
							dot(apex_to_point, self->direct)
								/ self->cos_half_angle_sq)));
	hrec->map = construct_cone_uv(self, &apex_to_point);
	hrec->mat_ptr = self->hitter.mat_ptr;
	return ;
}

static t_vec2	construct_cone_uv(
		const t_cone *self,
		const t_vec3 *center_to_point)
{
	static const int	unit_height = 5;
	const t_onb			onb = construct_onb(self->direct);
	const double		theta = atan2(
			dot(*center_to_point, onb.v[0]),
			dot(*center_to_point, onb.v[1]));
	const double		height = dot(*center_to_point, self->direct);

	return (construct_vec2(
			1.0 - (theta / (2.0 * M_PI) + 0.5),
			fmod(height, unit_height) / unit_height));
}
