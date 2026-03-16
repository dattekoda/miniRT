/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mlx_image_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:58:49 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:21:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rt_mlx_bonus.h"
#include "vec_bonus.h"
#include "result_bonus.h"
#include "rt_define_bonus.h"
#include <stdlib.h>
#include <stddef.h>
#include <X11/keysym.h>
#include <X11/X.h>

void		print_time(void);
int			close_window(t_rt_mlx *rt_mlx);
int			init_rt_mlx(t_rt_mlx *rt_mlx);
int			init_rt_img(t_rt_img *rt_img, void *mlx);
void		clear_rt_mlx(t_rt_mlx *rt_mlx);
static void	raw_rgb_arr_to_mlx_addr(
				void *mlx,
				t_rt_img *rt_img,
				const int *raw_rgb_arr);
static int	key_handler(int key, t_rt_mlx *rt_mlx);

int	draw_mlx_image(int **raw_rgb_arr)
{
	t_rt_mlx	rt_mlx;

	if (init_rt_mlx(&rt_mlx) == FAILURE)
	{
		clear_rt_mlx(&rt_mlx);
		return (FAILURE);
	}
	raw_rgb_arr_to_mlx_addr(rt_mlx.var.mlx, &rt_mlx.img, *raw_rgb_arr);
	free(*raw_rgb_arr);
	*raw_rgb_arr = NULL;
	print_time();
	mlx_put_image_to_window(
		rt_mlx.var.mlx,
		rt_mlx.var.win,
		rt_mlx.img.id,
		0,
		0);
	mlx_hook(rt_mlx.var.win, ClientMessage, NoEventMask, close_window, &rt_mlx);
	mlx_key_hook(rt_mlx.var.win, key_handler, &rt_mlx);
	mlx_loop(rt_mlx.var.mlx);
	return (SUCCESS);
}

static int	key_handler(int key, t_rt_mlx *rt_mlx)
{
	if (key == XK_Escape || key == XK_q)
		close_window(rt_mlx);
	return (0);
}

static void	raw_rgb_arr_to_mlx_addr(
				void *mlx,
				t_rt_img *rt_img,
				const int *raw_rgb_arr)
{
	size_t	xi;
	size_t	yi;
	size_t	x_base;
	char	*dst;

	yi = 0;
	dst = rt_img->addr;
	while (yi < g_window_height)
	{
		xi = 0;
		x_base = yi * g_window_width;
		while (xi < g_window_width)
		{
			dst += rt_img->bit_per_pixel;
			*(int *)dst = mlx_get_color_value(mlx, raw_rgb_arr[x_base + xi++]);
		}
		yi++;
	}
	return ;
}
