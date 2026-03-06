/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pertition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:21:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 21:35:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "axis.h"
#include "hitter_arr.h"
#include <assert.h>

size_t	pertition(t_hitter_arr hit_arr, int axis);

static void	case1(void)
{
	t_hitter	a = {.has_aabb = true, .aabb = {.centroid = {0.0, 0.0, 0.0}}};

	t_hitter_arr	arr = {.arr = (t_hitter *[]){&a}, .size = 1};
	size_t	pivot_idx = pertition(arr, X);
	assert(pivot_idx == 0);
	assert(arr.arr[pivot_idx]->aabb.centroid.e[0] == 0.0
		&& arr.arr[pivot_idx]->aabb.centroid.e[1] == 0.0
		&& arr.arr[pivot_idx]->aabb.centroid.e[2] == 0.0
	);
}

static void	case2(void)
{
	t_hitter	a = { .aabb = {.centroid = {0.0, 0.0, 0.0}}};
	t_hitter	b = { .aabb = {.centroid = {-1.0, 0.0, 0.0}}};

	t_hitter_arr	arr = {.arr = (t_hitter *[]){&a, &b}, .size = 2};
	size_t	pivot_idx = pertition(arr, X);
	assert(pivot_idx == 1);
	assert(arr.arr[pivot_idx]->aabb.centroid.e[0] == 0.0
		&& arr.arr[pivot_idx]->aabb.centroid.e[1] == 0.0
		&& arr.arr[pivot_idx]->aabb.centroid.e[2] == 0.0
	);
}

void	test_pertition(void)
{
	case1();
	case2();
	
}
