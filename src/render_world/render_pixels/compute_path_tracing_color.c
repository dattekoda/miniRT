/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_path_tracing_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:57:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/12 23:12:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "world.h"
#include "material.h"
#include "rt_define.h"
#include "vec_utils.h"
#include "rt_define.h"
#include "rt_utils.h"
#include <math.h>

static bool	is_killed_by_russian_roulette(size_t depth, t_color *attenuation);

#include "rt_debug.h"
#include <stdio.h>
#include <stdlib.h>
t_color	compute_path_tracing_color(
			const t_ray *ray,
			const t_world *world,
			size_t depth)
{
	t_range	range;
	t_hrec	hrec;
	t_srec	srec;

	range = construct_vec2(HIT_T_MIN, INFINITY);
	if (depth >= MAX_DEPTH)
		return (constant_vec3(1.0));
	if (!world->object_tree)
		return (world->ambient_light);
	if (!world->object_tree->hit(world->object_tree, ray, &hrec, &range))
		return (world->ambient_light);
	if (!hrec.mat_ptr->scatter(hrec.mat_ptr, world, &hrec, &srec))
		return (srec.attenuation);
	if (is_killed_by_russian_roulette(depth, &srec.attenuation))
		return (srec.attenuation);
	return (scal_mul_vec3(
			mul_vec3(
				srec.attenuation,
				compute_path_tracing_color(&srec.next_ray, world, depth + 1)),
			(srec.surface_pdf / srec.sampling_pdf)));
}

static bool	is_killed_by_russian_roulette(size_t depth, t_color *attenuation)
{
	double	live_prob;

	if (depth < RUSSIAN_ROULETTE_START_DEPTH)
		return (false);
	live_prob = fmax(
			fmax(
				attenuation->e[0],
				attenuation->e[1]),
			attenuation->e[2]);
	live_prob = clamp(live_prob, LIVE_PROBABILITY_MIN, 1.0);
	if (live_prob < random_01())
		return (true);
	*attenuation = scal_div_vec3(*attenuation, live_prob);
	return (false);
}
