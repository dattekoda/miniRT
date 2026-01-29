/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_split_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:45:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 19:27:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "best_split.h"
#include "hitter_arr.h"
#include "hitter_utils.h"
#include "libft.h"
#include "result.h"
#include "vec_utils.h"
#include "axis.h"
#include <math.h>
#include <stdlib.h>

void		sort_hit_arr(t_hitter_arr hit_arr, int axis);
static int	repare_surface_arr(t_hitter_arr hit_arr, double **left_arr_p,
				double **right_arr_p);
static int	find_best_left_size(t_hitter_arr hit_arr,
				size_t *best_left_size, double *best_cost);
t_aabb		surrounding_box(t_aabb box0, t_aabb box1);
double		calc_surface_area(const t_aabb aabb);
double		cost_func(const t_hitter_arr root, size_t left_size,
				double *left_area_arr, double *right_area_arr);

int	find_best_split_info(t_hitter_arr hit_arr,
	t_axis *best_axis, size_t *best_left_size)
{
	double	best_cost;
	double	tmp_cost;
	size_t	tmp_axis;
	size_t	tmp_left_size;

	*best_axis = X;
	*best_left_size = 0;
	best_cost = INFINITY;
	tmp_axis = 0;
	while (tmp_axis < 3)
	{
		sort_hit_arr(hit_arr, tmp_axis);
		if (find_best_left_size(hit_arr, tmp_left_size, &tmp_cost) == FAILURE)
			return (FAILURE);
		if (tmp_cost < best_cost)
		{
			best_cost = tmp_cost;
			*best_left_size = tmp_left_size;
			*best_axis = tmp_axis;
		}
		tmp_axis++;
	}
	return (SUCCESS);
}

static int	find_best_left_size(t_hitter_arr hit_arr,
	size_t *best_left_size, double *best_cost)
{
	double	*left_arr;
	double	*right_arr;
	size_t	tmp_left_size;
	double	tmp_cost;

	if (prepare_surface_arr(hit_arr, &left_arr, &right_arr) == FAILURE)
		return (FAILURE);
	tmp_left_size = 0;
	while (tmp_left_size < hit_arr.size)
	{
		tmp_cost = cost_func(hit_arr, tmp_left_size, left_arr, right_arr);
		if (tmp_cost < *best_cost)
		{
			*best_cost = tmp_cost;
			*best_left_size = tmp_left_size;
		}
		tmp_left_size++;
	}
	free(left_arr);
	free(right_arr);
	return (SUCCESS);
}

static int	prepare_surface_arr(t_hitter_arr hit_arr, double **left_arr_p,
		double **right_arr_p)
{
	t_aabb	aabb_left;
	t_aabb	aabb_right;
	size_t	left_size;
	size_t	right_size;

	*left_arr_p = ft_calloc(hit_arr.size, sizeof(double));
	*right_arr_p = ft_calloc(hit_arr.size, sizeof(double));
	if (!*left_arr_p || !*right_arr_p)
		return (free(*left_arr_p), free(*right_arr_p), FAILURE);
	aabb_left = construct_aabb(constant_vec3(0), constant_vec3(0));
	aabb_right = construct_aabb(constant_vec3(0), constant_vec3(0));
	left_size = 1;
	while (left_size < hit_arr.size)
	{
		right_size = hit_arr.size - left_size;
		aabb_left = surrounding_box(aabb_left, hit_arr.arr[left_size
				- 1]->aabb);
		aabb_right = surrounding_box(aabb_right, hit_arr.arr[right_size
				- 1]->aabb);
		(*left_arr_p)[left_size - 1] = calc_surface_area(aabb_left);
		(*right_arr_p)[right_size - 1] = calc_surface_area(aabb_right);
		left_size++;
	}
	return (SUCCESS);
}
