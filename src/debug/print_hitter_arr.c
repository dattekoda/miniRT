/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hitter_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:29:02 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 20:34:15 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include <stdio.h>

void		print_hitter(const t_hitter *hitter);
static void	print_surface_arr(size_t size, const double *arr);

void	print_hitter_arr(const t_hitter_arr *hit_arr)
{
	size_t	i;

	i = 0;
	fprintf(stderr, "--- hitter_arr ---\n");
	fprintf(stderr, "size:\t%zu\n", hit_arr->size);
	fprintf(stderr, "arr:\n");
	while (i < hit_arr->size)
		print_hitter(hit_arr->arr[i++]);
	fprintf(stderr, "left:\t");
	if (hit_arr->left_surface_arr)
		print_surface_arr(hit_arr->size, hit_arr->left_surface_arr);
	fprintf(stderr, "right:\t");
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
		fprintf(stderr, "%.2f", arr[i]);
		if (i != size - 1)
			fprintf(stderr, ", ");
		i++;
	}
	fprintf(stderr, "\n");
}
