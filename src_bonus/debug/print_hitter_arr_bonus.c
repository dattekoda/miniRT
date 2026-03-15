/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hitter_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:29:02 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr_bonus.h"
#include <stdio.h>

void		print_hitter(const t_hitter *hitter);
static void	print_surface_arr(size_t size, const double *arr);

void	print_hitter_arr(const t_hitter_arr *hit_arr)
{
	size_t	i;

	i = 0;
	printf("--- hitter_arr ---\n");
	printf("size:\t%zu\n", hit_arr->size);
	printf("arr:\n");
	while (i < hit_arr->size)
		print_hitter(hit_arr->arr[i++]);
	printf("left:\t");
	if (hit_arr->left_surface_arr)
		print_surface_arr(hit_arr->size, hit_arr->left_surface_arr);
	printf("right:\t");
	if (hit_arr->right_surface_arr)
		print_surface_arr(hit_arr->size, hit_arr->right_surface_arr);
	return ;
}

static void	print_surface_arr(size_t size, const double *arr)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("%.2f", arr[i]);
		if (i != size - 1)
			printf(", ");
		i++;
	}
	printf("\n");
}
