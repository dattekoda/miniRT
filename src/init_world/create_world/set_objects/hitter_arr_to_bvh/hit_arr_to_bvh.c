/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_arr_to_bvh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:31:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 18:21:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "hitter_arr.h"
#include "hitter.h"
#include "result.h"
#include "best_split.h"
#include "libft.h"

t_hitter		*generate_tree(t_hitter *lhs, t_hitter *rhs);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);
static void		sort_hit_arr(t_hitter_arr hit_arr, int axis);
double			cost_func(const t_hitter_arr root, size_t left_size);
int				find_best_split_info(t_hitter_arr hit_arr, t_best_split *info);
static bool		is_component_lower(const t_hitter *subject,
				const t_hitter *base, int axis);
static void	swap_hitter(t_hitter **a, t_hitter **b);
static size_t	pertition(t_hitter_arr hit_arr, int axis);

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
	t_best_split	info;
	t_hitter		*lhs;
	t_hitter		*rhs;

	if (hit_arr.size == 1)
		return (hit_arr.arr[0]);
	if (hit_arr.size == 2)
		return (generate_tree(hit_arr.arr[0], hit_arr.arr[1]));
	if (find_best_split_info(hit_arr, &info) == FAILURE)
		return (NULL);
	sort_hit_arr(hit_arr, info.axis);
	lhs = generate_bvh_recursive(construct_hitter_arr(hit_arr.arr, info.left_size));
	if (!lhs)
		return (NULL);
	rhs = generate_bvh_recursive(construct_hitter_arr(
			hit_arr.arr + info.left_size, hit_arr.size - info.left_size));
	if (!rhs)
		return (lhs->clear(lhs), NULL);
	return (generate_tree(lhs, rhs));
}

static void	sort_hit_arr(t_hitter_arr hit_arr, int axis)
{
	size_t	pivot_location;

	if (hit_arr.size <= 1)
		return ;
	if (hit_arr.size == 2)
	{
		if (is_component_lower(hit_arr.arr[0], hit_arr.arr[1], axis))
			swap_hitter(hit_arr.arr, hit_arr.arr + 1);
		return ;
	}
	pivot_location = pertition(hit_arr, axis);
	sort_hit_arr(construct_hitter_arr(hit_arr.arr,pivot_location - 1), axis);
	sort_hit_arr(construct_hitter_arr(hit_arr.arr, pivot_location + 1), axis);
}

static size_t	pertition(t_hitter_arr hit_arr, int axis)
{
	size_t		left;
	size_t		right;
	t_hitter	**pivot_p;

	left = 0;
	right = hit_arr.size - 1;
	pivot_p = &hit_arr.arr[hit_arr.size];
	while (left < right)
	{
		while (left < hit_arr.size
			&& !is_component_lower(hit_arr.arr[left], *pivot_p ,axis))
			left++;
		while (0 < right
			&& is_component_lower(hit_arr.arr[right], *pivot_p ,axis))
			right--;
		if (right <= left)
			break ;
		swap_hitter(&hit_arr.arr[left++], &hit_arr.arr[right--]);
	}
	swap_hitter(&hit_arr.arr[left], *pivot_p);
	return (left);
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
	return (subject->aabb.centroid.e[axis] < base->aabb.centroid.e[axis]);
}
