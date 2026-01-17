/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_arr_to_bvh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:31:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:53:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "hitter_arr.h"
#include "hitter.h"
#include "result.h"
#include "best_split.h"

t_hitter		*gen_tree(t_hitter *lhs, t_hitter *rhs);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);
static void		sort_hit_arr(t_hitter_arr hit_arr, int axis);
double			cost_func(const t_hitter_arr root, size_t left_size);

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
	lhs = gen_bvh_recursive(
			construct_hitter_arr(hit_arr.arr, result.left_size));
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
