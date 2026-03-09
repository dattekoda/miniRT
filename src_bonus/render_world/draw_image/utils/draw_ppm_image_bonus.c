/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ppm_image_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:49:14 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:31:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_bonus.h"
#include "rt_define_bonus.h"
#include <stdio.h>
#include <stdlib.h>

static void	put_rgb_color(int rgb_color);

void	draw_ppm_image(int **raw_rgb_arr)
{
	size_t	xi;
	size_t	yi;
	size_t	x_base;

	printf("P3\n%d %d\n255\n", g_window_width, g_window_height);
	yi = 0;
	while (yi < g_window_height)
	{
		xi = 0;
		x_base = yi * g_window_width;
		while (xi < g_window_width)
			put_rgb_color((*raw_rgb_arr)[x_base + xi++]);
		yi++;
	}
	free(*raw_rgb_arr);
	return ;
}

static void	put_rgb_color(int rgb_color)
{
	const int	r = (rgb_color >> 16) & 0xFF;
	const int	g = (rgb_color >> 8) & 0xFF;
	const int	b = rgb_color & 0xFF;

	printf("%d %d %d\n", r, g, b);
	return ;
}
