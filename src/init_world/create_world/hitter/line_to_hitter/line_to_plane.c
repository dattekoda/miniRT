/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:16:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:56:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "line_to_element.h"
#include "vec_utils.h"
#include "init_world_utils.h"
#include "result.h"
#include "libft.h"

static int	line_to_plane_param(char *line, t_plane *plane_param);
int			line_to_material(
				t_line_reader *line_reader,
				t_material **mat_pp,
				const t_element *element);

int	line_to_plane(t_hitter **plane, char *line)
{
	t_plane	plane_param;

	ft_bzero(&plane_param, sizeof(t_plane));
	line_to_plane_param(line, &plane_param);
	*plane = generate_plane(plane_param);
	if (!*plane)
		return (FAILURE);
	return (SUCCESS);
}

/*
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225 lambertian bump
*/
static int	line_to_plane_param(char *line, t_plane *plane_param)
{
	t_line_reader	line_reader;

	line_reader = construct_line_reader(line);
	line_reader.idx = g_infinite_table[PLANE]->id_len;
	plane_param->normal = normalize(plane_param->normal);
	if (line_to_material(
			&line_reader, &plane_param->hitter.mat_ptr, g_info_table[PLANE])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
