/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_arr_to_bvh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:31:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 21:34:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "best_split.h"
#include "hitter.h"
#include "hitter_arr.h"
#include "init_world_define.h"
#include "axis.h"
#include "libft.h"
#include "result.h"

static t_hitter	*generate_bvh_recursive(t_hitter_arr hit_arr);
t_hitter		*generate_tree(t_hitter *lhs, t_hitter *rhs);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);
void			sort_hit_arr(t_hitter_arr hit_arr, int axis);
double			cost_func(const t_hitter_arr root, size_t left_size);
int				find_best_split_info(t_hitter_arr hit_arr,
					t_axis *best_axis, size_t *best_left_size);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);

int	hit_arr_to_bvh(t_hitter **root, t_hitter_arr hit_arr)
{
	*root = NULL;
	if (hit_arr.size == 0)
		return (SUCCESS);
	*root = generate_bvh_recursive(hit_arr);
	if (!*root)
		return (FAILURE);
	return (SUCCESS);
}

static t_hitter	*generate_bvh_recursive(t_hitter_arr hit_arr)
{
	t_axis		axis;
	size_t		left_size;
	t_hitter	*lhs;
	t_hitter	*rhs;

	if (hit_arr.size == 1)
		return (hit_arr.arr[0]);
	if (hit_arr.size == 2)
		return (generate_tree(hit_arr.arr[0], hit_arr.arr[1]));
	if (find_best_split_info(hit_arr, &axis, &left_size) == FAILURE)
		return (NULL);
	sort_hit_arr(hit_arr, axis);
	lhs = generate_bvh_recursive(
			construct_hitter_arr(hit_arr.arr, left_size));
	if (!lhs)
		return (NULL);
	rhs = generate_bvh_recursive(
			construct_hitter_arr(
				hit_arr.arr + left_size, hit_arr.size - left_size));
	if (!rhs)
		return (lhs->clear(lhs), NULL);
	return (generate_tree(lhs, rhs));
}
