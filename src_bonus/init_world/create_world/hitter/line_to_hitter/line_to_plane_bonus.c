/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_plane_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:16:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane_bonus.h"
#include "line_to_element_bonus.h"
#include "vec_utils_bonus.h"
#include "init_world_utils_bonus.h"
#include "result_bonus.h"
#include "libft.h"

static int	line_to_plane_param(const char *line, t_plane *plane_param);

int	line_to_plane(t_hitter **plane, const char *line)
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
static int	line_to_plane_param(const char *line, t_plane *plane_param)
{
	size_t	i;

	i = g_element_table[PLANE]->id_len;
	token_to_vec(line, &i, &plane_param->point);
	token_to_vec(line, &i, &plane_param->normal);
	plane_param->normal = normalize(plane_param->normal);
	if (line_to_material(
			line, &i, &plane_param->hitter.mat_ptr, g_element_table[PLANE])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
