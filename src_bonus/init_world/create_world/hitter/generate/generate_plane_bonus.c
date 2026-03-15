/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_plane_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:31:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane_bonus.h"
#include "rt_utils_bonus.h"
#include "libft.h"
#include <stdlib.h>

static t_plane	construct_plane(t_plane plane_param);
bool			hit_plane(
					const void *s,
					const t_ray *ray, t_hrec *hrec, t_range *range);

t_hitter	*generate_plane(t_plane plane_param)
{
	t_plane	*p;

	if (!plane_param.hitter.mat_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_plane));
	if (!p)
	{
		plane_param.hitter.mat_ptr->clear(plane_param.hitter.mat_ptr);
		free(plane_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_plane(plane_param);
	return ((t_hitter *)p);
}

static t_plane	construct_plane(t_plane plane_param)
{
	t_plane	plane;

	ft_memmove(&plane, &plane_param, sizeof(t_plane));
	plane.hitter.type = PLANE;
	plane.hitter.hit = hit_plane;
	plane.hitter.clear = clear_hitter;
	plane.hitter.has_aabb = false;
	return (plane);
}
