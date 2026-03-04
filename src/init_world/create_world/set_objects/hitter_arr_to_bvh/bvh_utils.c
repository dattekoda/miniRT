/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:29:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 16:59:46 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "init_world_define.h"
#include "rt_define.h"
#include "vec_utils.h"
#include "axis.h"
#include <math.h>

double	calc_cost(
			t_hitter_arr hit_arr,
			size_t left_size)
{
	const size_t	right_size = hit_arr.size - left_size;
	const double	left_surface_area
		= hit_arr.left_surface_arr[left_size - 1];;
	const double	right_surface_area
		= hit_arr.right_surface_arr[left_size];

	return (2 * COST_AABB_INTERSECTION + (left_surface_area * left_size
			+ right_surface_area * right_size) * COST_ELEMENT_INTERSECTION
		/ hit_arr.left_surface_arr[hit_arr.size - 1]);
}

double	calc_surface_area(const t_aabb aabb)
{
	double	s[3];

	s[A_X] = (aabb.max.e[A_X] - aabb.min.e[A_X]);
	s[A_Y] = (aabb.max.e[A_Y] - aabb.min.e[A_Y]);
	s[A_Z] = (aabb.max.e[A_Z] - aabb.min.e[A_Z]);
	return (s[A_X] * s[A_Y] + s[A_Y] * s[A_Z] + s[A_Z] * s[A_X]);
}
