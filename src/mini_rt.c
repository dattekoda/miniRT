/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 19:51:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "result.h"
#include "libft.h"
#include <stdlib.h>

int		init_world(t_world *world, int *option_flag, int argc, char *argv[]);
void	clear_world(t_world world);
int		paint_pixel(t_color **pxl_arr_p, const t_world *world);

int	mini_rt(int argc, char *argv[])
{
	int		option_flag;
	t_world	world;
	t_color	*pixel_arr;

	ft_bzero(&world, sizeof(t_world));
	if (init_world(&world, &option_flag, argc, argv) == FAILURE)
		return (EXIT_FAILURE);
	pixel_arr = NULL;
	if (paint_pixel(&pixel_arr, &world) == FAILURE)
	{
		clear_world(world);
		return (EXIT_FAILURE);
	}
	clear_world(world);
	if (draw_image(&pixel_arr) == FAILURE)
	{
		
		return (FAILURE);
	}
	return (SUCCESS);
}
