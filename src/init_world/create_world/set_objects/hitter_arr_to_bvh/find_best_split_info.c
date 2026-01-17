/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_split_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:45:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/18 00:14:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "best_split.h"
#include "libft.h"
#include <math.h>

double	cost_func(const t_hitter_arr root, size_t left_size);
double	calc_surface_area(const t_aabb aabb);
t_aabb	surrounding_box(t_aabb box0, t_aabb box1);

static t_best_split	construct_best_split(int axis, size_t left_size,
	double cost)
{
	t_best_split	rev;

	rev.axis = axis;
	rev.left_size = left_size;
	rev.cost = cost;
	return (rev);
}

t_best_split	find_best_split_info(t_hitter_arr hit_arr)
{
	t_best_split	best_info;
	double			cost;
	size_t			axis;
	size_t			left_size;

	best_info = construct_best_split(0, 0, INFINITY);
	axis = 0;
	while (axis < 3)
	{
		sort_hit_arr(hit_arr, axis);
		prepare_surface_arr(hit_arr);
		left_size = 1;
		while (left_size <= hit_arr.size)
		{
			cost = cost_func(hit_arr, left_size);
			if (cost < best_info.cost)
				best_info = construct_best_split(
					axis, left_size, cost);
			left_size++;
		}
		axis++;
	}
	return (best_info);
}

static void	prepare_surface_arr(t_hitter_arr hit_arr)
{
	t_aabb	aabb_left;
	t_aabb	aabb_right;
	size_t	i;

	aabb_left = construct_aabb(constant_vec3(0), constant_vec3(0));
	aabb_right = construct_aabb(constant_vec3(0), constant_vec3(0));
	i = 0;
	while (i < hit_arr.size)
	{
		aabb_left = surrounding_box(aabb_left, hit_arr.arr[i]->aabb);
		aabb_right = surrounding_box(aabb_right, hit_arr.arr[hit_arr.size - i]->aabb);
		hit_arr.left_area_arr[i] = calc_surface_area(aabb_left);
		hit_arr.right_area_arr[i] = calc_surface_area(aabb_right);
		i++;
	}
}
