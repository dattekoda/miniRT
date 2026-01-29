/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_split_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:45:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 23:42:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "hitter_utils.h"
#include "libft.h"
#include "result.h"
#include "vec_utils.h"
#include "axis.h"
#include <math.h>
#include <stdlib.h>

void		sort_hit_arr(t_hitter_arr hit_arr, int axis);
int			prepare_surface_arr(
				t_hitter_arr hit_arr,
				double **left_arr_p,
				double **right_arr_p);
static int	find_best_left_size(
				t_hitter_arr hit_arr,
				size_t *best_left_size,
				double *best_cost);
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
		if (find_best_left_size(hit_arr, &tmp_left_size, &tmp_cost) == FAILURE)
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
	free(left_arr);
	free(right_arr);
	return (SUCCESS);
}
