/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_split_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:45:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 14:52:03 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "hitter_utils.h"
#include "libft.h"
#include "result.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "split.h"
#include <math.h>
#include <stdlib.h>

// void		sort_hit_arr(t_hitter_arr hit_arr, int axis);
int			prepare_surface_arr(
				t_hitter_arr hit_arr,
				double **left_arr_p,
				double **right_arr_p);
t_compar	get_compar_func(t_axis axis);
static int	find_best_left_size(
				t_hitter_arr hit_arr,
				size_t *best_left_size,
				double *best_cost);
double		cost_func(const t_hitter_arr root, size_t left_size,
				double *left_area_arr, double *right_area_arr);

#include <stdio.h>
int	find_best_split_info(t_hitter_arr hit_arr, t_split *best)
{
	t_split	tmp;

	*best = construct_split(A_X, 1, INFINITY);
	tmp = construct_split(A_X, 1, A_X);
	while (tmp.axis < 3)
	{
		ft_qsort((char *)hit_arr.arr, hit_arr.size,
			sizeof(t_hitter *), get_compar_func(tmp.axis));
		if (find_best_left_size(hit_arr, &tmp.left_size, &tmp.cost) == FAILURE)
			return (FAILURE);
		// fprintf(stderr, "axis:\t%d, tmp.left_size:\t%zu, tmp.cost:\t%f\n", tmp.axis, tmp.left_size, tmp.cost);
		if (tmp.cost < best->cost)
			*best = tmp;
		tmp.axis++;
	}
	return (SUCCESS);
}

static int	find_best_left_size(
				t_hitter_arr hit_arr,
				size_t *best_left_size,
				double *best_cost)
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
	fprintf(stderr, "tmp_left_size:\t%zu, tmp_cost:\t%f\n", tmp_left_size, tmp_cost);
	free(left_arr);
	free(right_arr);
	return (SUCCESS);
}
