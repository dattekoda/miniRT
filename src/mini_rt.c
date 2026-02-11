/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/11 18:40:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "result.h"
#include "option.h"
#include "rt_utils.h"
#include "libft.h"
#include <stdlib.h>

int		init_world(t_world *world, int *option_flag, int argc, char *argv[]);
int		render_pixels(
			t_color **pixel_arr_p,
			const t_world *world,
			bool is_phong);
int		draw_image(const t_color *pixel_arr, bool is_ppm_mode);
void	clear_world(t_world world);


#include <stdio.h>
int	mini_rt(int argc, char *argv[])
{
	int		option_flag;
	t_world	world;
	t_color	*pixel_arr;

	ft_bzero(&world, sizeof(t_world));
	if (init_world(&world, &option_flag, argc, argv) == FAILURE)
		return (EXIT_FAILURE);
	if (render_pixels(&pixel_arr, &world,
		option_flag & OPT_ARTIFICIAL) == FAILURE)
	{
		clear_world(world);
		return (EXIT_FAILURE);
	}
	clear_world(world);\
	if (draw_image(pixel_arr, option_flag & OPT_PPM) == FAILURE)
	{
		free(pixel_arr);
		return (FAILURE);
	}
	free(pixel_arr);
	return (SUCCESS);
}
