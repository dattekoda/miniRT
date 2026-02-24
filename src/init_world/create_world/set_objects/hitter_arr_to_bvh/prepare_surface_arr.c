/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_surface_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:39:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/24 19:26:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "hitter_arr.h"
#include "result.h"
#include "libft.h"
#include <stdlib.h>

double	calc_surface_area(const t_aabb aabb);
t_aabb	surrounding_box(t_aabb box0, t_aabb box1);
t_aabb	construct_aabb(t_point3 min, t_point3 max);

void	prepare_surface_arr(t_hitter_arr hit_arr)
{
	t_aabb	aabb_left;
	t_aabb	aabb_right;
	size_t	left_size;
	size_t	right_size;

	aabb_left = hit_arr.arr[0]->aabb;
	aabb_right = hit_arr.arr[hit_arr.size - 1]->aabb;
	left_size = 1;
	while (left_size < hit_arr.size)
	{
		right_size = hit_arr.size - left_size - 1;
		aabb_left = surrounding_box(aabb_left,
			hit_arr.arr[left_size - 1]->aabb);
		aabb_right = surrounding_box(aabb_right,
			hit_arr.arr[right_size]->aabb);
		(hit_arr.left_surface_arr)[left_size - 1] = calc_surface_area(aabb_left);
		(hit_arr.right_surface_arr)[right_size] = calc_surface_area(aabb_right);
		left_size++;
	}
	return ;
}
