/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:08:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/18 00:12:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"
#include "vec_utils.h"

static bool	hit_aabb(const void *s, t_ray ray, t_hrec *hrec, t_range range);

t_aabb	construct_aabb(t_point3 min, t_point3 max)
{
	t_aabb	rev;

	rev.min = min;
	rev.max = max;
	rev.centroid = add_vec3(min, max);
	rev.hit = hit_aabb;
}

static bool	hit_aabb(const void *s, t_ray ray, t_hrec *hrec, t_range range)
{
	t_aabb	*self;

	self = s;
	return (true);
}
