/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:38:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/07 21:56:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include "world.h"
#include "result.h"
#include "option.h"
#include "vec_utils.h"
#include "libft.h"
#include <unistd.h>

t_color			calc_pixel_color(
					int xi,
					int yi,
					const t_world *world,
					int option_flag);
static void		accumulate_pixel_arr(
					t_color *pixel_arr,
					const t_world *world,
					int option_flag);
static void		print_remaining(size_t yi);

int	render_pixel(
		t_color **pixel_arr_p,
		const t_world *world,
		int option_flag)
{
	const int	window_width = WINDOW_WIDTH;
	const int	window_height = WINDOW_WIDTH * ASPECT_RATIO;

	*pixel_arr_p = ft_calloc(window_width * window_height, sizeof(t_color));
	if (!*pixel_arr_p)
		return (FAILURE);
	accumlate_pixel_arr(*pixel_arr_p, world);
	return (SUCCESS);
}

static void	accumulate_pixel_arr(
				t_color *pixel_arr,
				const t_world *world,
				int option_flag)
{
	static const int	window_height
		= WINDOW_WIDTH * ASPECT_RATIO;
	size_t				yi;
	size_t				xi;
	size_t				x_base;

	yi = 0;
	while (yi < window_height)
	{
		x_base = yi * WINDOW_WIDTH;
		print_remaining(yi);
		xi = 0;
		while (xi < WINDOW_WIDTH)
		{
			pixel_arr[x_base + xi] = calc_pixel_color(xi, yi, world, option_flag);
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
	ft_putnbr_fd((int)yi, STDERR_FILENO);
}
