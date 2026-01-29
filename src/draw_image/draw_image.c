/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:45:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 18:37:58 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include "vec.h"
#include "result.h"

// int	draw_ppm_image(const t_color *pixel_arr);

int	draw_image(const t_color *pixel_arr, int option_flag, void **mlx_p)
{
	if (option_flag & OPT_PPM)
		;
	(void)mlx_p;
	(void)pixel_arr;
	return (SUCCESS);
}
