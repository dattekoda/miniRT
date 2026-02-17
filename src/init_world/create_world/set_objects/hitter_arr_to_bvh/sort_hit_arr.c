/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hit_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:22:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/18 21:39:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "rt_utils.h"
#include <aio.h>

bool			is_component_higher(const t_hitter *subject,
					const t_hitter *base, int axis);
ssize_t			pertition(t_hitter_arr hit_arr, int axis);
t_hitter_arr	construct_hitter_arr(t_hitter **arr, size_t size);
static t_hitter	*decide_pivot(t_hitter_arr arr, int axis);


// left is bigger!
void	sort_hit_arr(t_hitter_arr hit_arr, int axis)
{
	ssize_t	last_idx;

	if (hit_arr.size <= 1)
		return ;
	last_idx = pertition(hit_arr, axis);
	sort_hit_arr(construct_hitter_arr(
					hit_arr.arr,
					last_idx), axis);
	sort_hit_arr(construct_hitter_arr(
					hit_arr.arr + last_idx,
					(ssize_t)hit_arr.size - last_idx), axis);
	return ;
}

// 2, 4, 6


// left is bigger!
ssize_t	pertition(t_hitter_arr hit_arr, int axis)
{
	t_hitter	*pivot;
	ssize_t		left;
	ssize_t		right;

	pivot = decide_pivot(hit_arr, axis);
	printf("pivot: %f\n", pivot->aabb.centroid.e[axis]);
	left = -1;
	right = (ssize_t)hit_arr.size;
	while (left < right)
	{
		while (is_component_higher(hit_arr.arr[++left], pivot, axis))
			;
		while (is_component_higher(pivot, hit_arr.arr[--right], axis))
			;
		printf("left: %zu right:%zu\n", left, right);
		if (left >= right)
			break ;
		printf("before\n");
		printf("left: %f\n", hit_arr.arr[left]->aabb.centroid.e[axis]);
		printf("right: %f\n", hit_arr.arr[right]->aabb.centroid.e[axis]);
		rt_swap(&hit_arr.arr[left],
			&hit_arr.arr[right], sizeof(t_hitter *));
		printf("left: %f\n", hit_arr.arr[left]->aabb.centroid.e[axis]);
		printf("right: %f\n", hit_arr.arr[right]->aabb.centroid.e[axis]);
		printf("after\n");
	}
	return (right);
}

static t_hitter	*decide_pivot(t_hitter_arr arr, int axis)
{
	size_t	mid;
	size_t	tail;

	tail = arr.size - 1;
	mid = tail / 2;
	if (is_component_higher(arr.arr[0], arr.arr[mid], axis))
	{
		if (is_component_higher(arr.arr[mid], arr.arr[tail], axis))
			return (arr.arr[mid]);
		else if (is_component_higher(arr.arr[0], arr.arr[tail], axis))
			return (arr.arr[tail]);
		return (arr.arr[0]);
	}
	if (is_component_higher(arr.arr[0], arr.arr[tail], axis))
		return (arr.arr[0]);
	else if (is_component_higher(arr.arr[mid], arr.arr[tail], axis))
		return (arr.arr[tail]);
	return (arr.arr[mid]);
}

bool	is_component_higher(const t_hitter *subject, const t_hitter *base,
		int axis)
{
	printf("sub: %f\n", subject->aabb.centroid.e[axis]);
	printf("bas: %f\n\n", base->aabb.centroid.e[axis]);
	if (!subject->has_aabb || !base->has_aabb)
		return (false);
	return (subject->aabb.centroid.e[axis] > base->aabb.centroid.e[axis]);
}
