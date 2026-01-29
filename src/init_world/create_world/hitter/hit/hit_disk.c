/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:52:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/30 01:59:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "plane.h"
#include "solution.h"
#include "rt_utils.h"
#include "vec_utils.h"
#include <math.h>

static t_solution	init_solution_context(const t_point3 *point,
						const t_vec3 *normal, const t_ray *ray);
bool				hit_plane(
						const void *s,
						const t_ray *ray, t_hrec *hrec, t_range *range);

bool	hit_disk(
			const void *s, const t_ray *ray, t_hrec *hrec, t_range *range)
{
	const t_disk	*self;
	t_plane			plane;
	t_solution		solu;

	self = s;
	plane.normal = self->normal;
	plane.point = self->center;
	plane.hitter = self->hitter;
	if (!hit_plane(&plane, ray, hrec, range))
		return (false);
	if (length_squared_vec3(
			sub_vec3(hrec->point, self->center)) > pow(self->radius, 2))
		return (false);
	return (true);
}
