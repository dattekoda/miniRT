/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:16:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 18:21:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "hitter.h"
#include "vec.h"
#include "result.h"
#include <stddef.h>

int	line_to_plane(t_hitter **plane, const char *line)
{
	size_t			i;
	t_plane			shape_param;
	t_color			raw_color;

	i = 2;
	token_to_vec(line, &i, &shape_param.point);
	token_to_vec(line, &i, &shape_param.normal);
	token_to_vec(line, &i, &raw_color);
	*plane = generate_plane(shape_param);
	if (!*plane)
		return (FAILURE);
	return (SUCCESS);
}
