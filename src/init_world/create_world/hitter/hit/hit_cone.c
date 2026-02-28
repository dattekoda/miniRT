/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:57:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/28 18:38:13 by ikawamuk         ###   ########.fr       */
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
static void			assign_cone_hrec(
						const t_cone *self,
						const t_ray *ray,
						t_hrec *hrec,
						double solution);
static t_vec2		construct_cone_uv(const t_cone *self, const t_vec3 *cp);
static t_vec3		calc_coeff(
						const t_vec3 *ray_direct,
						const t_vec3 *c_to_ori,
						const t_vec3 *cone_dir,
						double half_angle);

// TODO: still unsure but maybe need fix range->e[1] to update.
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
	const t_vec3	center_to_ray_origin = sub_vec3(ray->origin, self->center);

	solu->coeff = calc_coeff(
			&ray->direct,
			&center_to_ray_origin,
			&self->direct,
			self->half_angle);
	solu->discriminant = calc_discriminant(solu);
	return ;
}

static t_vec3	calc_coeff(
		const t_vec3 *ray_dir,
		const t_vec3 *center_to_ray_origin,
		const t_vec3 *cone_dir,
		double half_angle)
{
	const double	dot_rdir__cdir = dot(*ray_dir, *cone_dir);
	const double	dot_cdir__c_to_ro = dot(*cone_dir, *center_to_ray_origin);
	const double	dot_c_to_ro__rdir = dot(*center_to_ray_origin, *ray_dir);
	const double	cos_pow2 = pow(cos(half_angle), 2);

	return (construct_vec3(
			pow(dot_rdir__cdir, 2)
			- length_squared_vec3(*ray_dir) * cos_pow2,
			dot_rdir__cdir * dot_cdir__c_to_ro
			- dot_c_to_ro__rdir * cos_pow2,
			pow(dot_c_to_ro__rdir, 2)
			- length_squared_vec3(*center_to_ray_origin) * cos_pow2));
}

static void	assign_cone_hrec(
				const t_cone *self,
				const t_ray *ray,
				t_hrec *hrec,
				double solution)
{
	t_vec3	center_to_point;

	hrec->ray_in = *ray;
	hrec->param_t = solution;
	hrec->point = at_ray(ray, hrec->param_t);
	center_to_point = sub_vec3(hrec->point, self->center);
	hrec->normal = normalize(sub_vec3(center_to_point,
				scal_mul_vec3(self->direct,
					dot(center_to_point, self->direct)
					/ pow(self->half_angle, 2))));
	hrec->mat_ptr = self->hitter.mat_ptr;
	hrec->map = construct_cone_uv(self, &center_to_point);
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
