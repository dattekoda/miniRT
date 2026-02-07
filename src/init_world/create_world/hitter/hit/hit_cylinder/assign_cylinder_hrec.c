/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_cylinder_hrec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:47:39 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/08 06:43:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "solution.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>

static t_vec2		construct_cylinder_uv(
						const t_vec3 *center_to_point,
						const t_vec3 *direct,
						double tmp_height,
						double height);
static t_vec3		calc_cylinder_normal(
						const t_cylinder *self,
						const t_solution *solu,
						double tmp_height);


void	assign_cylinder_hrec(
			const t_cylinder *self,
			const t_ray *ray,
			t_hrec *hrec,
			const t_solution *solu)
{
	const t_vec3	center_to_point = sub_vec3(solu->point, self->center);
	const double	tmp_height = dot(center_to_point, self->direct);

	hrec->mat_ptr = self->hitter.mat_ptr;
	hrec->param_t = solu->solution;
	hrec->point = at_ray(ray, hrec->param_t);
	hrec->ray_in = *ray;
	hrec->normal = calc_cylinder_normal(self, &solu, tmp_height);
	hrec->map = construct_cylinder_uv(
					&center_to_point,
					&self->direct,
					tmp_height,
					self->height);
}

static t_vec3	calc_cylinder_normal(
					const t_cylinder *self,
					const t_solution *solu,
					double tmp_height)
{
	t_point3	point_on_axis;

	point_on_axis
		= add_vec3(self->center, scal_mul_vec3(self->direct, tmp_height));
	return (scal_div_vec3(sub_vec3(solu->point, point_on_axis), self->radius));
}

static t_vec2	construct_cylinder_uv(
					const t_vec3 *center_to_point,
					const t_vec3 *direct,
					double tmp_height,
					double height)
{
	t_onb	onb;
	double	theta;

	onb = construct_onb(*direct);
	theta = atan2(
		dot(*center_to_point, onb.v[0]),
		dot(*center_to_point, onb.v[1]));
	return (construct_vec2(
			1.0 - (theta / (2.0 * M_PI) + 0.5),
			tmp_height / height));
}
