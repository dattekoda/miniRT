/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_split_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:45:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/18 01:45:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "best_split.h"
#include "vec_utils.h"
#include "libft.h"
#include "result.h"
#include <math.h>

double	cost_func(const t_hitter_arr root, size_t left_size,
	double *left_arr, double *right_arr);
double	calc_surface_area(const t_aabb aabb);
t_aabb	surrounding_box(t_aabb box0, t_aabb box1);
t_aabb	construct_aabb(t_point3 min, t_point3 max);

static t_best_split	construct_best_split(int axis, size_t left_size,
	double cost)
{
	t_best_split	rev;

	rev.axis = axis;
	rev.left_size = left_size;
	rev.cost = cost;
	return (rev);
}

int	find_best_split_info(t_hitter_arr hit_arr, t_best_split *best_info)
{
	double			cost;
	size_t			axis;
	size_t			left_size;
	double			*left_arr;
	double			*right_arr;

	*best_info = construct_best_split(0, 0, INFINITY);
	axis = 0;
	while (axis < 3)
	{
		sort_hit_arr(hit_arr, axis);
		if (prepare_surface_arr(hit_arr, left_arr, right_arr) == FAILURE)
			return (FAILURE);
		left_size = 1;
		while (left_size < hit_arr.size)
		{
			cost = cost_func(hit_arr, left_size, left_arr, right_arr);
			if (cost < best_info->cost)
				*best_info = construct_best_split(
					axis, left_size, cost);
			left_size++;
		}
		free(left_arr);
		free(right_arr);
		axis++;
	}
	return (best_info);
}

static int	prepare_surface_arr(t_hitter_arr hit_arr,
	double *left_arr, double *right_arr)
{
	t_aabb	aabb_left;
	t_aabb	aabb_right;
	size_t	left_size;
	size_t	right_size;

	left_arr = ft_calloc(hit_arr.size, sizeof(double));
	if (!left_arr)
		return (FAILURE);
	right_arr = ft_calloc(hit_arr.size, sizeof(double));
	if (!right_arr)
		return (free(left_arr), FAILURE);
	aabb_left = construct_aabb(constant_vec3(0), constant_vec3(0));
	aabb_right = construct_aabb(constant_vec3(0), constant_vec3(0));
	left_size = 1;
	while (left_size < hit_arr.size)
	{
		right_size = hit_arr.size - left_size;
		aabb_left = surrounding_box(aabb_left, hit_arr.arr[left_size - 1]->aabb);
		aabb_right = surrounding_box(aabb_right, hit_arr.arr[right_size - 1]->aabb);
		left_arr[left_size - 1] = calc_surface_area(aabb_left);
		right_arr[right_size - 1] = calc_surface_area(aabb_right);
		left_size++;
	}
	return (SUCCESS);
}
