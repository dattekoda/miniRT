/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:20:58 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_bonus.h"
#include "result_bonus.h"
#include "option_bonus.h"
#include "vec_utils_bonus.h"
#include "rt_utils_bonus.h"
#include "rt_define_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

int		render_pixels(
			int **raw_rgb_arr,
			const t_world *world,
			bool is_phong);
int		draw_image(int **raw_rgb_arr, bool is_ppm_mode);
void	clear_world(t_world *world);

/*
@brief responsible for free(world)
*/
int	render_world(t_world *world, int option_flag)
{
	int	*raw_rgb_arr;

	if (render_pixels(&raw_rgb_arr, world, option_flag & OPT_ARTIFICIAL)
		== FAILURE)
	{
		clear_world(world);
		return (FAILURE);
	}
	clear_world(world);
	if (draw_image(&raw_rgb_arr, option_flag & OPT_PPM) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
