/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:29:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 20:54:03 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "init_world_define.h"
#include "rt_define.h"
#include "vec_utils.h"
#include "axis.h"
#include <math.h>

t_aabb			construct_aabb(t_point3 min, t_point3 max);

double	calc_cost(
			t_hitter_arr hit_arr,
			size_t left_size)
{
	const size_t	right_size = hit_arr.size - left_size;
	const double	left_surface_area
		= hit_arr.left_surface_arr[left_size - 1];;
	const double	right_surface_area
		= hit_arr.right_surface_arr[right_size - 1];

	return (2 * COST_AABB_INTERSECTION + (left_surface_area * left_size
			+ right_surface_area * right_size) * COST_ELEMENT_INTERSECTION
		/ hit_arr.left_surface_arr[hit_arr.size - 1]);
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

#include "rt_debug.h"
double	calc_surface_area(const t_aabb aabb)
{
	double	s[3];

	s[A_X] = (aabb.max.e[A_X] - aabb.min.e[A_X]);
	s[A_Y] = (aabb.max.e[A_Y] - aabb.min.e[A_Y]);
	s[A_Z] = (aabb.max.e[A_Z] - aabb.min.e[A_Z]);
	return (s[A_X] * s[A_Y] + s[A_Y] * s[A_Z] + s[A_Z] * s[A_X]);
}
