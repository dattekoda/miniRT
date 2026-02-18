/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:45:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 15:11:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <stdbool.h>

void	draw_ppm_image(int **raw_rgb_arr);
int		draw_mlx_image(int **raw_rgb_arr);

/*
@brief responsible for free(*raw_rgb_arr)
*/
int	draw_image(int **raw_rgb_arr, bool is_ppm_mode)
{
	if (is_ppm_mode)
		draw_ppm_image(raw_rgb_arr);
	else
		if (draw_mlx_image(raw_rgb_arr) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}
