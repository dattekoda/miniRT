/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_arr_to_bvh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:31:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/18 02:05:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "hitter_arr.h"
#include "hitter.h"
#include "result.h"
#include "best_split.h"
#include "libft.h"

t_hitter		*gen_tree(t_hitter *lhs, t_hitter *rhs);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);
static void		sort_hit_arr(t_hitter_arr hit_arr, int axis);
double			cost_func(const t_hitter_arr root, size_t left_size);
int				find_best_split_info(t_hitter_arr hit_arr, t_best_split *info);
static bool		is_component_higher(const t_hitter *subject,
				const t_hitter *base, int axis);
static void	swap_hitter(t_hitter **a, t_hitter **b);

int	hit_arr_to_bvh(t_hitter **root, t_hitter_arr hit_arr)
{
	*root = NULL;
	if (hit_arr.size == 0)
		return (SUCCESS);
	*root = gen_bvh_recursive(hit_arr);
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
	if (find_best_split_info(hit_arr, &info) == FAILURE)
		return (NULL);
	sort_hit_arr(hit_arr, info.axis);
	lhs = gen_bvh_recursive(construct_hitter_arr(hit_arr.arr, info.left_size));
	if (!lhs)
		return (NULL);
	rhs = gen_bvh_recursive(construct_hitter_arr(
			hit_arr.arr + info.left_size, hit_arr.size - info.left_size));
	if (!rhs)
		return (lhs->clear(lhs), NULL);
	return (gen_tree(lhs, rhs));
}

static void	sort_hit_arr(t_hitter_arr hit_arr, int axis)
{
	t_hitter	**pivot_p;
	size_t		left;
	size_t		right;

	if (hit_arr.size <= 1)
		return ;
	if (hit_arr.size == 2)
	{
		if (is_component_higher(hit_arr.arr[0], hit_arr.arr[1], axis))
			swap_hitter(hit_arr.arr, hit_arr.arr + 1);
		return ;
	}
	left = 0;
	right = hit_arr.size - 1;
	pivot_p = hit_arr.arr;
	while (left < right)
	{
		while (left < hit_arr.size
			&& !is_component_higher(hit_arr.arr[left], *pivot_p ,axis))
			left++;
		while (0 < right
			&& is_component_higher(hit_arr.arr[right], *pivot_p ,axis))
			right--;
		if (right <= left)
			break ;
		swap_hitter(&hit_arr.arr[left++], &hit_arr.arr[right--]);
	}
	swap_hitter(&hit_arr.arr[left], pivot_p);
	sort_hit_arr(construct_hitter_arr(hit_arr.arr, left), axis);
	sort_hit_arr(construct_hitter_arr(hit_arr.arr, right), axis);
}

static void	swap_hitter(t_hitter **a, t_hitter **b)
{
	t_hitter	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static bool	is_component_higher(const t_hitter *subject,
	const t_hitter *base, int axis)
{
	if (!subject->has_aabb || !base->has_aabb)
		return (false);
	return (subject->aabb.centroid.e[axis] > base->aabb.centroid.e[axis]);
}
