/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_split_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:45:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 20:19:31 by khanadat         ###   ########.fr       */
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
void		prepare_surface_arr(t_hitter_arr hit_arr);
t_compar	get_compar_func(t_axis axis);
static void	find_best_left_size(
				t_hitter_arr hit_arr,
				t_split		*best);
double		calc_cost(
				t_hitter_arr hit_arr,
				size_t left_size);

#include <stdio.h>
#include "rt_debug.h"
void	find_best_split_info(t_hitter_arr hit_arr, t_split *best)
{
	t_split	tmp;

	*best = construct_split(A_X, 1, INFINITY);
	tmp = construct_split(A_X, 1, INFINITY);
	while (tmp.axis < 3)
	{
		ft_qsort((char *)hit_arr.arr, hit_arr.size,
			sizeof(t_hitter *), get_compar_func(tmp.axis));
		find_best_left_size(hit_arr, &tmp);
		if (tmp.cost < best->cost)
			*best = tmp;
		tmp.axis++;
	}
	return ;
}

static void	find_best_left_size(
				t_hitter_arr hit_arr,
				t_split		*best)
{
	t_split	tmp;

	prepare_surface_arr(hit_arr);
	tmp = construct_split(A_NOTHING, 0, INFINITY);
	while (tmp.left_size < hit_arr.size)
	{
		print_split(best);
		tmp.cost = calc_cost(hit_arr, tmp.left_size);
		if (tmp.cost < best->cost)
		{
			best->cost = tmp.cost;
			best->left_size = tmp.left_size;
		}
		// fprintf(stderr, "inside find_best_left_size: ");
		// print_split(&tmp);
		tmp.left_size++;
	}
	exit(2);
	return ;
}
