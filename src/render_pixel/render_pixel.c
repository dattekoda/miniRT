/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:38:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 18:34:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include "world.h"
#include "result.h"
#include "libft.h"

int	render_pixel(t_color **pxl_arr_p, const t_world *world)
{
	const int	window_width = WINDOW_WIDTH;
	const int	window_height = WINDOW_WIDTH * ASPECT_RATIO;

	*pxl_arr_p = ft_calloc(window_width * window_height, sizeof(t_color));
	if (!*pxl_arr_p)
		return (FAILURE);
	(void)world;
	return (SUCCESS);
}
