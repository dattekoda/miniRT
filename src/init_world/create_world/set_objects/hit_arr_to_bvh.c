/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_arr_to_bvh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:31:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 20:56:32 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "hitter_arr.h"
#include "hitter.h"
#include "result.h"
#include <math.h>

t_hitter		*gen_tree(t_hitter *lhs, t_hitter *rhs);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);
static void		sort_hit_arr(t_hitter_arr hit_arr, int axis);

int	hit_arr_to_bvh(t_hitter **root, t_hitter_arr hit_arr)
{
	*root = NULL;
	if (hit_arr.size == 0)
		return (SUCCESS);
	*root = gen_bvh_recursive(construct_hitter_arr(hit_arr.arr, hit_arr.size));
	if (!*root)
		return (FAILURE);
	return (SUCCESS);
}

typedef struct s_best_split
{
	int		axis;
	size_t	left_size;
	double	cost;
}	t_best_split;

static t_best_split	construct_best_split(int axis, size_t left_size, double cost)
{
	t_best_split	rev;

	rev.axis = axis;
	rev.left_size = left_size;
	rev.cost =  cost;
	return (rev);
}

static t_hitter	*gen_bvh_recursive(t_hitter_arr hit_arr)
{
	t_best_split	result;
	t_hitter		*lhs;
	t_hitter		*rhs;

	if (hit_arr.size == 1)
		return (hit_arr.arr[0]);
	if (hit_arr.size == 2)
		return (gen_tree(hit_arr.arr[0], hit_arr.arr[1]));
	result = find_best_split_result(hit_arr);
	sort_hit_arr(hit_arr, 0);
	lhs = gen_bvh_recursive(construct_hitter_arr(hit_arr.arr, result.left_size));
	if (!lhs)
		return (NULL);
	rhs = gen_bvh_recursive(construct_hitter_arr(
		hit_arr.arr + result.left_size, hit_arr.size - result.left_size));
	if (!rhs)
		return (lhs->clear(lhs), NULL);
	return (gen_tree(lhs, rhs));
}

static void	sort_hit_arr(t_hitter_arr hit_arr, int axis)
{
	
}

static t_best_split	find_best_split_result(t_hitter_arr hit_arr)
{
	size_t			axis;
	t_best_split	result;
	t_best_split	tmp_result;

	result = construct_best_split(0, 0 ,INFINITY);
	axis = 0;
	while (axis < 3)
	{
		sort_hit_arr(hit_arr, axis);
		tmp_result = find_best_split_result_in_the_axis(hit_arr);
		if (tmp_result.cost < result.cost)
			result = construct_best_split(axis, tmp_result.left_size, tmp_result.cost);
		axis++;
	}
	return (result);
}

double	cost_func(const t_hitter_arr root, size_t left_size);

static t_best_split	find_best_split_result_in_the_axis(t_hitter_arr hit_arr)
{
	t_best_split	result;
	double			tmp_cost;
	size_t			i;

	result = construct_best_split(0, 0, INFINITY);
	i = 0;
	while (i < hit_arr.size)
	{
		tmp_cost = cost_func(hit_arr, i);
		if (tmp_cost < result.cost)
			result = construct_best_split(0, i, tmp_cost);
		i++;
	}
	return (result);
}
