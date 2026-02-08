/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_tracing_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:57:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/08 19:32:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "world.h"
#include "hitter.h"
#include "rt_define.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>

t_color	get_path_tracing_color(
			const t_ray *ray,
			const t_world *world,
			size_t depth)
{
	t_hrec	hrec;
	t_range	range;

	range = construct_vec2(HIT_T_MIN, INFINITY);
	if (depth >= MAX_DEPTH)
		return (constant_vec3(1.0));
	if (!world->object_tree
		|| !world->object_tree->hit(world->object_tree, &ray, &hrec, &range))
		return (world->ambient_light);
	
}