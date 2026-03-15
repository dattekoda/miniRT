/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:51:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element_bonus.h"
#include "init_world_utils_bonus.h"
#include "triangle_bonus.h"
#include "vec_utils_bonus.h"
#include <stddef.h>

static int	line_to_triangle_param(
				const char *line,
				t_triangle *triangle_param);

/*
"tri 1.0,1.0,1.0 2.0,2.0,2.0 30,30,30 255,255,0"
*/
int	line_to_triangle(t_hitter **triangle, const char *line)
{
	t_triangle	triangle_param;

	ft_bzero(&triangle_param, sizeof(t_triangle));
	line_to_triangle_param(line, &triangle_param);
	*triangle = generate_triangle(triangle_param);
	if (!*triangle)
		return (FAILURE);
	return (SUCCESS);
}

static int	line_to_triangle_param(const char *line, t_triangle *triangle_param)
{
	size_t	line_idx;

	line_idx = g_element_table[TRIANGLE]->id_len;
	token_to_vec(line, &line_idx, &triangle_param->vertex[0]);
	token_to_vec(line, &line_idx, &triangle_param->vertex[1]);
	token_to_vec(line, &line_idx, &triangle_param->vertex[2]);
	if (line_to_material(
			line,
			&line_idx,
			&triangle_param->hitter.mat_ptr,
			g_element_table[TRIANGLE])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
