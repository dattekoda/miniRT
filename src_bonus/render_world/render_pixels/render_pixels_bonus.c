/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:38:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define_bonus.h"
#include "rt_utils_bonus.h"
#include "world_bonus.h"
#include "result_bonus.h"
#include "option_bonus.h"
#include "vec_utils_bonus.h"
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

	set_random_seed_from_time();
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

	percentage = (int)((double)yi * inv_h_mul_100 + 0.5);
	if (percentage == old_percentage)
		return ;
	ft_putstr_fd("\rScanlines remaining: ", STDERR_FILENO);
	ft_putnbr_fd(percentage, STDERR_FILENO);
	ft_putstr_fd("%", STDERR_FILENO);
	old_percentage = percentage;
}

static int	convert_into_raw_rgb(t_color color)
{
	t_color	gamma_encoded_color;
	int		r;
	int		g;
	int		b;

	gamma_encoded_color = map_vec3(color, sqrt);
	r = (int)round((double)0xFF * clamp(gamma_encoded_color.e[0], 0.0, 1.0));
	g = (int)round((double)0xFF * clamp(gamma_encoded_color.e[1], 0.0, 1.0));
	b = (int)round((double)0xFF * clamp(gamma_encoded_color.e[2], 0.0, 1.0));
	return ((r << 16) | (g << 8) | b);
}
