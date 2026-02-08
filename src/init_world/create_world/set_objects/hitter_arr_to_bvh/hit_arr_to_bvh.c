/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_arr_to_bvh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:31:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 16:43:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"
#include "hitter_arr.h"
#include "init_world_define.h"
#include "axis.h"
#include "libft.h"
#include "result.h"

static int		base_case(t_hitter **hitter, t_hitter_arr hit_arr);
static int	generate_bvh_recursive(t_hitter **hitter, t_hitter_arr hit_arr);
t_hitter		*generate_tree(t_hitter *lhs, t_hitter *rhs);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);
void			sort_hit_arr(t_hitter_arr hit_arr, int axis);
int				find_best_split_info(t_hitter_arr hit_arr,
					t_axis *best_axis, size_t *best_left_size);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);

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
	t_axis		axis;
	size_t		left_size;
	t_hitter	*lhs;
	t_hitter	*rhs;

	if (hit_arr.size < 3)
		return (base_case(hitter, hit_arr));
	if (find_best_split_info(hit_arr, &axis, &left_size) == FAILURE)
		return (FAILURE);
	sort_hit_arr(hit_arr, axis);
	if (generate_bvh_recursive(&lhs,
			construct_hitter_arr(hit_arr.arr, left_size)) == FAILURE) 
		return (FAILURE);
	if (generate_bvh_recursive(&rhs,
			construct_hitter_arr(
				hit_arr.arr + left_size, hit_arr.size - left_size)) == FAILURE)
		return (lhs->clear(lhs), FAILURE);
	*hitter = generate_tree(lhs, rhs);
		if (!*hitter)
			return (FAILURE);
	return (SUCCESS);
}

static int	base_case(t_hitter **hitter, t_hitter_arr hit_arr)
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
