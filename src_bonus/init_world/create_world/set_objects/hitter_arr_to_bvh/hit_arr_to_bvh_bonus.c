/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_arr_to_bvh_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:31:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_bonus.h"
#include "hitter_arr_bonus.h"
#include "init_world_define_bonus.h"
#include "libft.h"
#include "rt_utils_bonus.h"
#include "result_bonus.h"
#include "tree_bonus.h"
#include "split_bonus.h"

t_hitter		*generate_tree(t_hitter *lhs, t_hitter *rhs);
void			find_best_split_info(t_hitter_arr hit_arr, t_split *best);
t_hitter_arr	construct_lhs_hitter_arr(
					t_hitter_arr hitter_arr,
					size_t best_left_size);
t_hitter_arr	construct_rhs_hitter_arr(
					t_hitter_arr hitter_arr,
					size_t best_left_size);
t_compar		get_compar_func(t_axis axis);
static int		generate_bvh_recursive(t_hitter **hitter, t_hitter_arr hit_arr);
static int		generate_bvh_base_case(t_hitter **hitter, t_hitter_arr hit_arr);

int	hit_arr_to_bvh(t_hitter **root, t_hitter_arr hit_arr)
{
	*root = NULL;
	if (hit_arr.size == 0)
		return (SUCCESS);
	if (generate_bvh_recursive(root, hit_arr) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	generate_bvh_recursive(t_hitter **hitter, t_hitter_arr hit_arr)
{
	t_split		best;
	t_hitter	*lhs;
	t_hitter	*rhs;

	if (hit_arr.size < 3)
		return (generate_bvh_base_case(hitter, hit_arr));
	find_best_split_info(hit_arr, &best);
	ft_qsort((char *)hit_arr.arr,
		hit_arr.size, sizeof(t_hitter *), get_compar_func(best.axis));
	if (generate_bvh_recursive(
			&lhs,
			construct_lhs_hitter_arr(hit_arr, best.left_size)) == FAILURE)
		return (FAILURE);
	if (generate_bvh_recursive(
			&rhs,
			construct_rhs_hitter_arr(hit_arr, best.left_size)) == FAILURE)
		return (clear_free_hitter(lhs), FAILURE);
	*hitter = generate_tree(lhs, rhs);
	if (!*hitter)
		return (FAILURE);
	return (SUCCESS);
}

static int	generate_bvh_base_case(t_hitter **hitter, t_hitter_arr hit_arr)
{
	if (hit_arr.size == 0)
	{
		*hitter = NULL;
		return (SUCCESS);
	}
	else if (hit_arr.size == 1)
	{
		*hitter = hit_arr.arr[0];
		return (SUCCESS);
	}
	else if (hit_arr.size == 2)
	{
		*hitter = generate_tree(hit_arr.arr[0], hit_arr.arr[1]);
		if (!*hitter)
			return (FAILURE);
		return (SUCCESS);
	}
	return (FAILURE);
}
