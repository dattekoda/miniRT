/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_height_and_assign.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:47:39 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/28 17:03:05 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "solution.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>

static void			assign_cylinder_hrec(
					const t_cylinder *self,
					const t_ray *ray,
					t_hrec *hrec,
					const t_solution *solu);
static t_vec2		construct_cylinder_uv(
						const t_vec3 *center_to_point,
						const t_vec3 *direct,
						double tmp_height,
						double height);

/*
@brief check if point is inside height and assign hrec. 
In order to avoid calculate center_to_point and
tmp_height twice, this function has respoinsible for assign hrec.
*/
bool	validate_height_and_assign(
			const t_cylinder *self,
			const t_ray *ray,
			t_hrec *hrec,
			t_solution *solu)
{
	t_vec3	center_to_point;
	double	tmp_height;

	solu->point = at_ray(ray, solu->solution);
	center_to_point = sub_vec3(solu->point, self->center);
	tmp_height = dot(center_to_point, self->direct);
	if (tmp_height < 0 || self->height < tmp_height)
		return (false);
	assign_cylinder_hrec(self, ray, hrec, solu);
	hrec->normal = scal_div_vec3(
		sub_vec3(
			center_to_point,
			scal_mul_vec3(
				self->direct,
				tmp_height)),
		self->radius);
	hrec->map = construct_cylinder_uv(
			&center_to_point,
			&self->direct,
			tmp_height,
			self->height);
	return (true);
}

static void	assign_cylinder_hrec(
			const t_cylinder *self,
			const t_ray *ray,
			t_hrec *hrec,
			const t_solution *solu)
{
	hrec->mat_ptr = self->hitter.mat_ptr;
	hrec->param_t = solu->solution;
	hrec->point = at_ray(ray, hrec->param_t);
	hrec->ray_in = *ray;
	return ;
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
