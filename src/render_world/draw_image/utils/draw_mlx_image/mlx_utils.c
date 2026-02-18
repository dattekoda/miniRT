/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:22:49 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/12 23:18:15 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_mlx.h"
#include "result.h"
#include "rt_define.h"
#include "rt_utils.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

static int	init_rt_img(t_rt_img *rt_img, void *mlx);

/*
@brief not responsible for free vars
*/
int	init_rt_mlx(t_rt_mlx *rt_mlx)
{
	ft_bzero(rt_mlx, sizeof(t_rt_mlx));
	rt_mlx->var.mlx = mlx_init();
	if (!rt_mlx->var.mlx)
	{
		err_rt("mlx_init() failed.");
		return (FAILURE);
	}
	rt_mlx->var.win = mlx_new_window(
				rt_mlx->var.mlx,
				g_window_width,
				(int)(g_window_height),
				PROJECT_NAME);
	if (!rt_mlx->var.win)
	{
		err_rt("mlx_new_window() failed.");
		return (FAILURE);
	}
	if (init_rt_img(&rt_mlx->img, rt_mlx->var.mlx) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*
@brief not responsible for free vars
*/
static int	init_rt_img(t_rt_img *rt_img, void *mlx)
{
	rt_img->id = mlx_new_image(mlx,
		g_window_width,
		g_window_height);
	if (!rt_img->id)
	{
		err_rt("mlx_new_image() failed.");
		return (FAILURE);
	}
	rt_img->addr = mlx_get_data_addr(
		rt_img->id, \
		&rt_img->bpp, \
		&rt_img->line_len, \
		&rt_img->endian \
	);
	if (!rt_img->addr)
	{
		err_rt("mlx_get_data_addr() failed.");
		return (FAILURE);
	}
	rt_img->bpp /= 8;
	return (SUCCESS);
}

void	clear_rt_mlx(t_rt_mlx *rt_mlx)
{
	if (rt_mlx->var.mlx && rt_mlx->img.id)
		mlx_destroy_image(rt_mlx->var.mlx, rt_mlx->img.id);
	if (rt_mlx->var.mlx && rt_mlx->var.win)
		mlx_destroy_window(rt_mlx->var.mlx, rt_mlx->var.win);
	// if (rt_mlx->var.mlx)
	// 	mlx_destroy_display(rt_mlx->var.mlx);
	if (rt_mlx->var.mlx)
		free(rt_mlx->var.mlx);
	return ;
}

int	close_window(t_rt_mlx *rt_mlx)
{
	clear_rt_mlx(rt_mlx);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}
