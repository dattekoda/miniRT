/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_hitter_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:42:36 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr_bonus.h"

static t_hitter_arr	construct_hitter_arr(
						t_hitter **arr,
						size_t size,
						double *left_surface_arr,
						double *right_surface_arr);

t_hitter_arr	construct_lhs_hitter_arr(
					t_hitter_arr hitter_arr,
					size_t best_left_size)
{
	return (construct_hitter_arr(
			hitter_arr.arr,
			best_left_size,
			hitter_arr.left_surface_arr,
			hitter_arr.right_surface_arr));
}

t_hitter_arr	construct_rhs_hitter_arr(
					t_hitter_arr hitter_arr,
					size_t best_left_size)
{
	return (construct_hitter_arr(
			hitter_arr.arr + best_left_size,
			hitter_arr.size - best_left_size,
			hitter_arr.left_surface_arr + best_left_size,
			hitter_arr.right_surface_arr + best_left_size));
}

static t_hitter_arr	construct_hitter_arr(
					t_hitter **arr,
					size_t size,
					double *left_surface_arr,
					double *right_surface_arr)
{
	t_hitter_arr	hit_arr;

	hit_arr.arr = arr;
	hit_arr.size = size;
	hit_arr.left_surface_arr = left_surface_arr;
	hit_arr.right_surface_arr = right_surface_arr;
	return (hit_arr);
}
