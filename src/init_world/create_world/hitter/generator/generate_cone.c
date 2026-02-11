/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:55:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/11 18:50:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "rt_utils.h"

bool			hit_cone(
					const void *s,
					const t_ray *ray, t_hrec *hrec, t_range *range);
static t_cone	construct_cone(t_cone shape_param);

/*
@brief responsible for free(mat_ptr)
*/
t_hitter	*generate_cone(t_cone shape_param)
{
	t_cone	*p;

	if (!shape_param.hitter.mat_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_cone));
	if (!p)
	{
		shape_param.hitter.mat_ptr->clear(shape_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_cone(shape_param);
	return ((t_hitter *)p);
}

static t_cone	construct_cone(t_cone cone_param)
{
	t_cone	cone;

	ft_memmove(&cone, &cone_param, sizeof(t_cone));
	cone.hitter.type = CYLINDER;
	cone.hitter.hit = hit_cone;
	cone.hitter.clear = clear_hitter;
	cone.hitter.has_aabb = false;
	return (cone);
}
