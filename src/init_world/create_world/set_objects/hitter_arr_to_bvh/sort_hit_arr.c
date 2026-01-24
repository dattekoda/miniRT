/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hit_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:22:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/24 22:23:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"

static bool		is_component_lower(const t_hitter *subject,
				const t_hitter *base, int axis);
static void	swap_hitter(t_hitter **a, t_hitter **b);
static size_t	pertition(t_hitter_arr hit_arr, int axis);
void	sort_hit_arr(t_hitter_arr hit_arr, int axis)
{
	size_t	pivot_location;

	if (hit_arr.size <= 1)
		return ;
	if (hit_arr.size == 2)
	{
		if (is_component_lower(hit_arr.arr[0], hit_arr.arr[1], axis))
			rt_swap(hit_arr.arr, hit_arr.arr + 1, sizeof(t_hitter **));
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
