/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_arr_to_bvh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:31:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/18 00:02:32 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "hitter_arr.h"
#include "hitter.h"
#include "result.h"
#include "best_split.h"
#include "libft.h"

t_hitter		*gen_tree(t_hitter *lhs, t_hitter *rhs);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size,
	double *left_arr, double *right_arr);
static void		sort_hit_arr(t_hitter_arr hit_arr, int axis);
double			cost_func(const t_hitter_arr root, size_t left_size);
t_best_split	find_best_split_info(t_hitter_arr hit_arr);

int	hit_arr_to_bvh(t_hitter **root, t_hitter_arr hit_arr)
{
	*root = NULL;
	if (hit_arr.size == 0)
		return (SUCCESS);
	hit_arr.left_area_arr = ft_calloc(hit_arr.size, sizeof(double));
	if (!hit_arr.left_area_arr)
		return (FAILURE);
	hit_arr.right_area_arr = ft_calloc(hit_arr.size, sizeof(double));
	if (!hit_arr.right_area_arr)
		return (free(hit_arr.left_area_arr), FAILURE);
	*root = gen_bvh_recursive(hit_arr);
	free(hit_arr.left_area_arr);
	free(hit_arr.right_area_arr);
	if (!*root)
		return (FAILURE);
	return (SUCCESS);
}

static t_hitter	*gen_bvh_recursive(t_hitter_arr hit_arr)
{
	t_best_split	info;
	t_hitter		*lhs;
	t_hitter		*rhs;

	if (hit_arr.size == 1)
		return (hit_arr.arr[0]);
	if (hit_arr.size == 2)
		return (gen_tree(hit_arr.arr[0], hit_arr.arr[1]));
	info = find_best_split_info(hit_arr);
	sort_hit_arr(hit_arr, info.axis);
	lhs = gen_bvh_recursive(
			construct_hitter_arr(hit_arr.arr, info.left_size,
			hit_arr.left_area_arr, hit_arr.right_area_arr));
	if (!lhs)
		return (NULL);
	rhs = gen_bvh_recursive(construct_hitter_arr(
			hit_arr.arr + info.left_size, hit_arr.size - info.left_size,
			hit_arr.left_area_arr, hit_arr.right_area_arr));
	if (!rhs)
		return (lhs->clear(lhs), NULL);
	return (gen_tree(lhs, rhs));
}

static void	sort_hit_arr(t_hitter_arr hit_arr, int axis)
{
	
}
