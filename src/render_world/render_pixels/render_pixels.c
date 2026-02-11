/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:38:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/11 22:03:33 by khanadat         ###   ########.fr       */
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

t_color			calc_sample_pixel_color(
					int xi,
					int yi,
					const t_world *world,
					bool is_phong);
static void		accumulate_pixel_arr(
					t_color *pixel_arr,
					const t_world *world,
					bool is_phong);
static void		print_remaining(size_t yi);

int	render_pixels(
		t_color **pixel_arr_p,
		const t_world *world,
		bool is_phong)
{
	*pixel_arr_p = ft_calloc(
			g_window_width * g_window_height,
			sizeof(t_color));
	if (!*pixel_arr_p)
		return (FAILURE);
	set_random_seed_from_time();
	accumulate_pixel_arr(*pixel_arr_p, world, is_phong);
	return (SUCCESS);
}

static void	accumulate_pixel_arr(
				t_color *pixel_arr,
				const t_world *world,
				bool is_phong)
{
	size_t				yi;
	size_t				xi;
	size_t				x_base;

	yi = 0;
	while (yi < g_window_height)
	{
		x_base = yi * g_window_width;
		print_remaining(yi);
		xi = 0;
		while (xi < g_window_width)
		{
			pixel_arr[x_base + xi]
				= calc_sample_pixel_color(xi, yi, world, is_phong);
			xi++;
		}
		yi++;
	}
	ft_putendl_fd("\nDone", STDERR_FILENO);
	return ;
}

static void	print_remaining(size_t yi)
{
	ft_putstr_fd("\rScanlines remaining: ", STDERR_FILENO);
	ft_putnbr_fd(
		(int)((double)yi / (double)(g_window_height - 1) * 100),
		STDERR_FILENO);
	ft_putstr_fd("%", STDERR_FILENO);
}
