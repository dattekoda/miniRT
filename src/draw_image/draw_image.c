/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:45:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/10 21:52:14 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "result.h"
#include "mlx.h"
#include "rt_utils.h"
#include "vec_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void		draw_ppm_image(const int *raw_rgb_arr);
int			draw_mlx_image(const int *raw_rgb_arr);
static int	*pixel_to_raw_rgb(const t_color *pixel_arr);
static int	convert_into_raw_rgb(t_color color);

int	draw_image(const t_color *pixel_arr, bool is_ppm_mode)
{
	int	*raw_rgb_arr;

	raw_rgb_arr = pixel_to_raw_rgb(pixel_arr);
	if (!raw_rgb_arr)
		return (FAILURE);
	if (is_ppm_mode)
		draw_ppm_image(raw_rgb_arr);
	else
		if (draw_mlx_image(raw_rgb_arr) == FAILURE)
			return (free(raw_rgb_arr), FAILURE);
	free(raw_rgb_arr);
	return (SUCCESS);
}

static int	*pixel_to_raw_rgb(const t_color *pixel_arr)
{
	int		*raw_rgb_arr;
	size_t	xi;
	size_t	yi;
	size_t	x_base;

	raw_rgb_arr = ft_calloc(g_window_width * g_window_height, sizeof(int));
	if (!raw_rgb_arr)
		return (NULL);
	xi = 0;
	yi = 0;
	while (yi < g_window_height)
	{
		x_base = yi * g_window_width;
		xi = 0;
		while (xi < g_window_width)
		{
			raw_rgb_arr[x_base + xi]
				= convert_into_raw_rgb(pixel_arr[x_base + xi]);
			xi++;
		}
		yi++;
	}
	return (raw_rgb_arr);
}

static int	convert_into_raw_rgb(t_color color)
{
	int		rgb_color[3];
	t_color	adjusted_color;

	adjusted_color = map_vec3(color, sqrt);
	rgb_color[0] = 256 * clamp(adjusted_color.e[0], 0.0, 0.999);
	rgb_color[1] = 256 * clamp(adjusted_color.e[1], 0.0, 0.999);
	rgb_color[2] = 256 * clamp(adjusted_color.e[2], 0.0, 0.999);
	return ((rgb_color[0] << 16) | (rgb_color[1] << 8) | rgb_color[2]);
}
