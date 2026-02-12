/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:03:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 20:17:23 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "rt_define.h"
#include <stdio.h>

void	print_vec3(t_vec3 v);

void	print_pixel_arr(t_color *pixel_arr)
{
	for (size_t iy = 0; iy < g_window_height; iy++)
	{
		size_t	x_base = iy * g_window_width;
		for (size_t ix = 0; ix < g_window_width; ix++)
		{
			if (iy % 23 == 0 && ix % 51 == 0)
				print_vec3(pixel_arr[x_base + ix]);
		}
	}
}

void	print_raw_rgb_arr(int *raw_rgb_arr)
{
	for (size_t iy = 0; iy < g_window_height; iy++)
	{
		size_t	x_base = iy * g_window_width;
		for (size_t ix = 0; ix < g_window_width; ix++)
		{
			if (iy % 23 == 0 && ix % 51 == 0)
			{
				int color = raw_rgb_arr[x_base + ix];
				printf("%d %d %d\n", color >> 16 & 0xFF,  color >> 8 & 0xFF, color & 0xFF);
			}
		}
	}
}
