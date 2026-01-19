/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:37:59 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/19 21:04:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"
#include "vec_utils.h"
#include "rt_utils.h"

static bool	hit_aabb(const void *s, t_ray ray, t_hrec *hrec, t_range range);

t_aabb	construct_aabb(t_point3 min, t_point3 max)
{
	t_aabb	aabb;

	aabb.min = min;
	aabb.max = max;
	aabb.centroid = add_vec3(min, max);
	aabb.hit = hit_aabb;
	return (aabb);
}

static bool	hit_aabb(const void *s, t_ray ray, t_hrec *hrec, t_range range)
{
	t_aabb	*self;
	t_range	tmp_range;
	size_t	axis;
	double	tmp_div;

	(void)hrec;
	self = s;
	axis = 0;
	while (axis < 3)
	{
		tmp_div = 1 / ray.direct.e[axis];
		tmp_range.e[0] = self->min.e[axis] - ray.origin.e[axis] * tmp_div;
		tmp_range.e[1] = self->max.e[axis] - ray.origin.e[axis] * tmp_div;
		if (tmp_div < 0.0f)
			rt_swap(&tmp_range.e[0], &tmp_range.e[1], sizeof(double));
		range.e[0] = fmix(tmp_range.e[0], range.e[0]);
		range.e[1] = fmax(tmp_range.e[1], range.e[1]);
		if (range.e[1] <= range.e[0])
			return (false);
		axis++;
	}
	return (true);
}
