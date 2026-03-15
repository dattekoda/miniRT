/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:37:59 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/16 00:12:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "axis.h"
#include "hitter.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include <math.h>

t_aabb	construct_aabb(t_point3 min, t_point3 max)
{
	t_aabb	aabb;

	aabb.min = min;
	aabb.max = max;
	aabb.centroid = scal_mul_vec3(add_vec3(min, max), 0.5);
	return (aabb);
}

bool	hit_aabb(
				const t_aabb *self,
				const t_ray *ray,
				const t_vec2 *range)
{
	t_range	tmp_range;
	double	tmp_min;
	double	tmp_max;
	t_axis	axis;

	tmp_min = range->e[E_MIN];
	tmp_max = range->e[E_MAX];
	axis = A_X;
	while (axis <= A_Z)
	{
		tmp_range.e[E_MIN] = (self->min.e[axis] - ray->origin.e[axis])
			* ray->inv_direct.e[axis];
		tmp_range.e[E_MAX] = (self->max.e[axis] - ray->origin.e[axis])
			* ray->inv_direct.e[axis];
		if (ray->inv_direct.e[axis] < 0)
			ft_swap(&tmp_range.e[E_MIN], &tmp_range.e[E_MAX], sizeof(double));
		tmp_min = fmax(tmp_range.e[E_MIN], tmp_min);
		tmp_max = fmin(tmp_range.e[E_MAX], tmp_max);
		if (tmp_max <= tmp_min)
			return (false);
		axis++;
	}
	return (true);
}

t_aabb	surrounding_box(t_aabb aabb1, t_aabb aabb2)
{
	return (construct_aabb(
			construct_vec3(
				fmin(aabb1.min.e[A_X], aabb2.min.e[A_X]),
				fmin(aabb1.min.e[A_Y], aabb2.min.e[A_Y]),
				fmin(aabb1.min.e[A_Z], aabb2.min.e[A_Z])),
			construct_vec3(
				fmax(aabb1.max.e[A_X], aabb2.max.e[A_X]),
				fmax(aabb1.max.e[A_Y], aabb2.max.e[A_Y]),
				fmax(aabb1.max.e[A_Z], aabb2.max.e[A_Z]))));
}
