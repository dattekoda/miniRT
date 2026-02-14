/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:51:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 14:44:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element.h"
#include "init_world_utils.h"
#include "triangle.h"
#include "vec_utils.h"
#include <stddef.h>

static int	line_to_triangle_param(
				const char *line,
				t_triangle *triangle_param);
static void	vertex_to_side(t_vec3 side[3], t_point3 vertex[3]);

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
	size_t	i;

	i = g_element_table[TRIANGLE]->id_len;
	token_to_vec(line, &i, &triangle_param->vertex[0]);
	token_to_vec(line, &i, &triangle_param->vertex[1]);
	token_to_vec(line, &i, &triangle_param->vertex[2]);
	vertex_to_side(triangle_param->side, triangle_param->vertex);
	triangle_param->normal = normalize(
			cross(triangle_param->side[0], triangle_param->side[1]));
	if (line_to_material(
			line, &i, &triangle_param->hitter.mat_ptr, g_element_table[TRIANGLE])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	vertex_to_side(t_vec3 side[3], t_point3 vertex[3])
{
	side[0] = sub_vec3(vertex[1], vertex[0]);
	side[1] = sub_vec3(vertex[2], vertex[1]);
	side[2] = sub_vec3(vertex[0], vertex[2]);
	return ;
}
