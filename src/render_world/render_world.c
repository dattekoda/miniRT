/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:20:58 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/11 22:36:05 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "result.h"
#include "option.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

int			render_pixels(
				t_color **pixel_arr_p,
				const t_world *world,
				bool is_phong);
int			draw_image(int **raw_rgb_arr, bool is_ppm_mode);
void		clear_world(t_world *world);
static int	pixel_arr_to_raw_rgb_arr(
				int **raw_rgb_arr,
				const t_color *pixel_arr);
static int	convert_into_raw_rgb(t_color color);

void	print_vec(t_vec3 v)
{
	for (int i = 0; i < 3; i++)
	{
		printf("e[%d]: %f\n", i, v.e[i]);
	}
}

void	print_pixel_arr(t_color *pixel_arr)
{
	for (size_t iy = 0; iy < g_window_height; iy++)
	{
		size_t	x_base = iy * g_window_width;
		for (size_t ix = 0; ix < g_window_width; ix++)
		{
			if (iy % 23 == 0 && ix % 51 == 0)
				print_vec(pixel_arr[x_base + ix]);
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

/*
@brief responsible for free(world)
*/
int	render_world(t_world *world, int option_flag)
{
	t_color	*pixel_arr;
	int		*raw_rgb_arr;

	if (render_pixels(&pixel_arr, world,
		option_flag & OPT_ARTIFICIAL) == FAILURE)
	{
		clear_world(world);
		return (FAILURE);
	}
	clear_world(world);
	print_pixel_arr(pixel_arr);
	if (pixel_arr_to_raw_rgb_arr(&raw_rgb_arr, pixel_arr) == FAILURE)
	{
		free(pixel_arr);
		return (FAILURE);
	}
	print_raw_rgb_arr(raw_rgb_arr);
	exit(1);
	free(pixel_arr);
	if (draw_image(&raw_rgb_arr, option_flag & OPT_PPM) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	pixel_arr_to_raw_rgb_arr(
				int **raw_rgb_arr,
				const t_color *pixel_arr)
{
	size_t	xi;
	size_t	yi;
	size_t	x_base;

	*raw_rgb_arr = ft_calloc(g_window_width * g_window_height, sizeof(int));
	if (!*raw_rgb_arr)
		return (FAILURE);
	yi = 0;
	while (yi < g_window_height)
	{
		xi = 0;
		x_base = yi * g_window_width;
		while (xi < g_window_width)
		{
			*raw_rgb_arr[x_base + xi]
				= convert_into_raw_rgb(pixel_arr[x_base + xi]);
			xi++;
		}
		yi++;
	}
	return (SUCCESS);
}

static int	convert_into_raw_rgb(t_color color)
{
	t_color	adjusted_color;
	int		rgb_color[3];

	fprintf(stderr, "%f\n", color.e[0]);
	adjusted_color = map_vec3(color, sqrt);
	fprintf(stderr, "%f\n", adjusted_color.e[0]);
	rgb_color[0] = 256.0 * clamp(adjusted_color.e[0], 0.0, 0.999);
	fprintf(stderr, "%d\n", rgb_color[0]);
	fprintf(stderr, "%f\n", color.e[1]);
	adjusted_color = map_vec3(color, sqrt);
	fprintf(stderr, "%f\n", adjusted_color.e[1]);
	rgb_color[1] = 256.0 * clamp(adjusted_color.e[1], 0.0, 0.999);
	fprintf(stderr, "%d\n", rgb_color[1]);
	fprintf(stderr, "%f\n", color.e[2]);
	adjusted_color = map_vec3(color, sqrt);
	fprintf(stderr, "%f\n", adjusted_color.e[2]);
	rgb_color[2] = 256.0 * clamp(adjusted_color.e[2], 0.0, 0.999);
	fprintf(stderr, "%d\n", rgb_color[2]);
	exit(1);
	rgb_color[1] = 256.0 * clamp(adjusted_color.e[1], 0.0, 0.999);
	rgb_color[2] = 256.0 * clamp(adjusted_color.e[2], 0.0, 0.999);
	return ((rgb_color[0] << 16) | (rgb_color[1] << 8) | rgb_color[2]);
}
