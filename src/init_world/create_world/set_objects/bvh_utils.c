/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:29:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 01:00:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"

static double	calc_surface_area(const t_aabb aabb);

double	cost_func(const t_hitter_arr root, size_t left_size)
{
	size_t	i;
	t_hitter_arr	left;
	t_hitter_arr	right;

	left = construct_hitter_arr(root.arr, left_size);
	right = construct_hitter_arr(root.arr + left_size, root.size - left_size);
	return (2 * T_AABB + 
		(left.surface_area * left.size + right.surface_area * right.size)
		* T_TRI / root.surface_area);
}

t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size)
{
	t_hitter_arr	rev;
	t_aabb			bounding_box;

	rev.arr = arr;
	rev.size = size;
	bounding_box = create_bounfing_aabb(rev);
	rev.surface_area = calc_surface_area(bounding_box);
	return (rev);
}

t_aabb	create_bounfing_aabb(const t_hitter_arr hit_arr)
{
	t_aabb	rev;
	size_t	i;

	i = 0;
	rev = construct_aabb(constant_vec(0), constant_vec(0));
	while (i < hit_arr.size)
		rev = surrounding_box(rev, hit_arr.arr[i++]->aabb);
	return (rev);
	
}

static t_aabb	surrounding_box(t_aabb box0, t_aabb box1)
{
	t_point3	small;
	t_point3	big;

	small = construct_vec(fmin(box0.min.e[0], box1.min.e[0]),
						fmin(box0.min.e[1], box1.min.e[1]),
						fmin(box0.min.e[2], box1.min.e[2]));
	big = construct_vec(fmax(box0.min.e[0], box1.min.e[0]),
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
