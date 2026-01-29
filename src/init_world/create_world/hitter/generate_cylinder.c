/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:07:16 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/29 20:00:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "rt_utils.h" // clear_hitter()

static t_cylinder	construct_cylinder(t_cylinder shape_param);
static t_aabb		construct_aabb(t_cylinder cylinder);

t_hitter	*generate_cylinder(t_cylinder cylinder_param)
{
	t_cylinder	*p;

	p = ft_calloc(1, sizeof(t_cylinder));
	if (!p)
	{
		cylinder_param.hitter.mat_ptr->clear(cylinder_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_cylinder(cylinder_param);
	return ((t_hitter *)p);
}

static t_cylinder	construct_cylinder(t_cylinder shape_param)
{
	t_cylinder	cylinder;

	ft_memmove(&cylinder, &shape_param, sizeof(t_cylinder));
	// cylinder.hitter.hit = hit_cylinder;
	cylinder.hitter.clear = clear_hitter;
	cylinder.hitter.has_aabb = true;
	cylinder.hitter.aabb = construct_aabb(cylinder);
	return (cylinder);
}

static t_aabb	construct_aabb(t_cylinder cylinder)
{
	t_aabb	aabb;

	ft_bzero(&aabb, sizeof(t_aabb));
	(void)cylinder;
	return (aabb);
}
