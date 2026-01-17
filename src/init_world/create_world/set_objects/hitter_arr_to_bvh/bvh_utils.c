/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:29:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/18 00:18:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "vec_utils.h"
#include <hitter_arr.h>

static double	calc_surface_area(const t_aabb aabb);
t_aabb			construct_aabb(t_point3 min, t_point3 max);

double	cost_func(const t_hitter_arr root, size_t left_size)
{
	size_t	right_size;
	double	left_surface_area;
	double	right_surface_area;

	right_size = root.size - left_size;
	left_surface_area = root.left_area_arr[left_size - 1];
	right_surface_area = root.right_area_arr[right_size - 1];
	return (2 * T_AABB
		+ (left_surface_area * left_size + right_surface_area * right_size)
		* T_TRI / root.left_area_arr[root.size - 1]);
}

t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size, double *left_arr, double *right_arr)
{
	t_hitter_arr	rev;
	t_aabb			bounding_box;

	rev.arr = arr;
	rev.size = size;
	rev.left_area_arr = left_arr;
	rev.right_area_arr = right_arr;
	return (rev);
}

t_aabb	surrounding_box(t_aabb box0, t_aabb box1)
{
	t_point3	small;
	t_point3	big;

	small = construct_vec3(
			fmin(box0.min.e[0], box1.min.e[0]),
			fmin(box0.min.e[1], box1.min.e[1]),
			fmin(box0.min.e[2], box1.min.e[2]));
	big = construct_vec3(
			fmax(box0.min.e[0], box1.min.e[0]),
			fmax(box0.min.e[1], box1.min.e[1]),
			fmax(box0.min.e[2], box1.min.e[2]));
	return (construct_aabb(small, big));
}

double	calc_surface_area(const t_aabb aabb)
{
	double	s[3];

	s[0] = (aabb.max.e[0] - aabb.min.e[0]);
	s[1] = (aabb.max.e[1] - aabb.min.e[1]);
	s[2] = (aabb.max.e[2] - aabb.min.e[2]);
	return (s[0] * s[1] + s[1] * s[2] + s[2] * s[0]);
}
