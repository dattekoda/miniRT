/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_tr_solution_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:23:54 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:31:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle_bonus.h"
#include "solution_bonus.h"
#include "vec_utils_bonus.h"
#include <math.h>

static double	calc_det(
					const t_triangle *self,
					const t_ray *ray,
					t_triangle_solu *tr_solu);
static double	calc_coeff0(
					const t_triangle *self,
					const t_ray *ray,
					t_triangle_solu *tr_solu);
static double	calc_coeff1(
					const t_triangle *self,
					const t_ray *ray,
					t_triangle_solu *tr_solu);

bool	is_valid_tr_solution(
		const t_triangle *self,
		const t_ray *ray,
		t_triangle_solu *tr_solu)
{
	t_solution	*solu;

	solu = (t_solution *)tr_solu;
	tr_solu->det = calc_det(self, ray, tr_solu);
	if (fequal(tr_solu->det, 0))
		return (false);
	solu->coeff.e[0] = calc_coeff0(self, ray, tr_solu);
	if (solu->coeff.e[0] < 0.0 || 1.0 < solu->coeff.e[0])
		return (false);
	solu->coeff.e[1] = calc_coeff1(self, ray, tr_solu);
	if (solu->coeff.e[1] < 0.0
		|| 1.0 < solu->coeff.e[0] + solu->coeff.e[1])
		return (false);
	solu->solution = tr_solu->div_det * dot(self->edge[1], tr_solu->cross[1]);
	return (true);
}

static double	calc_det(
		const t_triangle *self,
		const t_ray *ray,
		t_triangle_solu *tr_solu)
{
	tr_solu->cross[0] = cross(ray->direct, self->edge[1]);
	return (dot(tr_solu->cross[0], self->edge[0]));
}

static double	calc_coeff0(
		const t_triangle *self,
		const t_ray *ray,
		t_triangle_solu *tr_solu)
{
	tr_solu->div_det = 1 / tr_solu->det;
	tr_solu->ver0_to_origin = sub_vec3(ray->origin, self->vertex[0]);
	return (dot(tr_solu->ver0_to_origin, tr_solu->cross[0]) * tr_solu->div_det);
}

static double	calc_coeff1(
		const t_triangle *self,
		const t_ray *ray,
		t_triangle_solu *tr_solu)
{
	tr_solu->cross[1] = cross(tr_solu->ver0_to_origin, self->edge[0]);
	return (dot(ray->direct, tr_solu->cross[1]) * tr_solu->div_det);
}
