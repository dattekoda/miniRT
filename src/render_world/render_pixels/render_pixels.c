/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:38:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 15:38:00 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include "rt_utils.h"
#include "world.h"
#include "result.h"
#include "option.h"
#include "vec_utils.h"
#include "libft.h"
#include <unistd.h>
#include <math.h>

t_color			accumulate_sample_pixel_color(
					const t_world *world,
					bool is_phong,
					size_t xi,
					size_t yi);
static void		accumulate_raw_rgb_arr(
					int *raw_rgb_arr,
					const t_world *world,
					bool is_phong);
static void		print_remaining(size_t yi);
static int		convert_into_raw_rgb(t_color color);

int	render_pixels(
		int **raw_rgb_arr,
		const t_world *world,
		bool is_phong)
{
	*raw_rgb_arr = ft_calloc(
			g_window_width * g_window_height,
			sizeof(int));
	if (!*raw_rgb_arr)
		return (FAILURE);
	set_random_seed_from_time();
	accumulate_raw_rgb_arr(*raw_rgb_arr, world, is_phong);
	return (SUCCESS);
}

static void	accumulate_raw_rgb_arr(
				int *raw_rgb_arr,
				const t_world *world,
				bool is_phong)
{
	size_t	yi;
	size_t	xi;
	size_t	x_base;

	yi = 0;
	while (yi < g_window_height)
	{
		print_remaining(yi);
		x_base = yi * g_window_width;
		xi = 0;
		while (xi < g_window_width)
		{
			raw_rgb_arr[x_base + xi]
				= convert_into_raw_rgb(
					accumulate_sample_pixel_color(world, is_phong, xi, yi));
			xi++;
		}
		yi++;
	}
	ft_putendl_fd("\nDone", STDERR_FILENO);
	return ;
}

/*
@brief write() only when percentage changes
*/
static void	print_remaining(size_t yi)
{
	static const double	inv_h_mul_100
		= 1 / (WINDOW_WIDTH * ASPECT_RATIO - 1) * 100;
	static int			old_percentage = -1;
	int					percentage;

	percentage = (int)((double)yi * inv_h_mul_100);
	if (percentage == old_percentage)
		return ;
	ft_putstr_fd("\rScanlines remaining: ", STDERR_FILENO);
	ft_putnbr_fd(percentage, STDERR_FILENO);
	ft_putstr_fd("%", STDERR_FILENO);
	old_percentage = percentage;
}

static int	convert_into_raw_rgb(t_color color)
{
	t_color	adjusted_color;
	int		rgb_color[3];

	adjusted_color = map_vec3(color, sqrt);
	rgb_color[0] = 256.0 * clamp(adjusted_color.e[0], 0.0, 0.999);
	rgb_color[1] = 256.0 * clamp(adjusted_color.e[1], 0.0, 0.999);
	rgb_color[2] = 256.0 * clamp(adjusted_color.e[2], 0.0, 0.999);
	return ((rgb_color[0] << 16) | (rgb_color[1] << 8) | rgb_color[2]);
}
