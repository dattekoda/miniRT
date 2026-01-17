/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_split_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:45:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 21:42:02 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "best_split.h"
#include <math.h>

static t_best_split	construct_best_split(int axis, size_t left_size,
	double cost)
{
	t_best_split	rev;

	rev.axis = axis;
	rev.left_size = left_size;
	rev.cost = cost;
	return (rev);
}

static t_best_split	find_best_split_info(t_hitter_arr hit_arr)
{
	size_t			axis;
	t_best_split	info;
	t_best_split	tmp_info;

	info = construct_best_split(0, 0, INFINITY);
	axis = 0;
	while (axis < 3)
	{
		sort_hit_arr(hit_arr, axis);
		tmp_info = find_best_split_info_in_the_axis(hit_arr);
		if (tmp_info.cost < info.cost)
			info = construct_best_split(
					axis, tmp_info.left_size, tmp_info.cost);
		axis++;
	}
	return (info);
}

static t_best_split	find_best_split_info_in_the_axis(t_hitter_arr hit_arr)
{
	t_best_split	info;
	double			tmp_cost;
	size_t			i;

	info = construct_best_split(0, 0, INFINITY);
	i = 0;
	while (i < hit_arr.size)
	{
		tmp_cost = cost_func(hit_arr, i);
		if (tmp_cost < info.cost)
			info = construct_best_split(0, i, tmp_cost);
		i++;
	}
	return (info);
}
