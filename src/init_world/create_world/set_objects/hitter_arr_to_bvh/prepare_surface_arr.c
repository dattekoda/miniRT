/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_surface_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:39:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 23:43:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "hitter_arr.h"
#include "result.h"
#include "libft.h"
#include <stdlib.h>

double		calc_surface_area(const t_aabb aabb);
t_aabb		surrounding_box(t_aabb box0, t_aabb box1);
t_aabb	construct_aabb(t_point3 min, t_point3 max);

int	prepare_surface_arr(
				t_hitter_arr hit_arr,
				double **left_arr_p,
				double **right_arr_p)
{
	t_aabb	aabb_left;
	t_aabb	aabb_right;
	size_t	left_size;
	size_t	right_size;

	*left_arr_p = ft_calloc(hit_arr.size, sizeof(double));
	*right_arr_p = ft_calloc(hit_arr.size, sizeof(double));
	if (!*left_arr_p || !*right_arr_p)
		return (free(*left_arr_p), free(*right_arr_p), FAILURE);
	aabb_left = construct_aabb(constant_vec3(0), constant_vec3(0));
	aabb_right = construct_aabb(constant_vec3(0), constant_vec3(0));
	left_size = 1;
	while (left_size < hit_arr.size)
	{
		right_size = hit_arr.size - left_size;
		aabb_left = surrounding_box(aabb_left, hit_arr.arr[left_size
				- 1]->aabb);
		aabb_right = surrounding_box(aabb_right, hit_arr.arr[right_size
				- 1]->aabb);
		(*left_arr_p)[left_size - 1] = calc_surface_area(aabb_left);
		(*right_arr_p)[right_size - 1] = calc_surface_area(aabb_right);
		left_size++;
	}
	return (SUCCESS);
}
