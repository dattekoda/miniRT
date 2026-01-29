/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:16:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 22:19:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "init_world_utils.h"
#include "result.h"
#include "libft.h"

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

	i = g_infinite_table[PLANE]->id_len;
	token_to_vec(line, &i, &plane_param->point);
	token_to_vec(line, &i, &plane_param->normal);
}
