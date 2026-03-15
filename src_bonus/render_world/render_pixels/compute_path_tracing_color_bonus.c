/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_path_tracing_color_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:57:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 23:03:26 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"
#include "render_task_bonus.h"
#include "world_bonus.h"
#include "material_bonus.h"
#include "rt_define_bonus.h"
#include "vec_utils_bonus.h"
#include "rt_define_bonus.h"
#include "rt_utils_bonus.h"
#include <math.h>

static bool	is_killed_by_russian_roulette(
		size_t depth,
		t_color *attenuation,
		uint64_t *seed);

t_color	compute_path_tracing_color(
			const t_ray *ray,
			t_render_task *r_task,
			size_t depth)
{
	t_range	range;
	t_hrec	hrec;
	t_srec	srec;

	range = construct_vec2(HIT_T_MIN, INFINITY);
	if (depth >= MAX_DEPTH)
		return (fill_vec3(0.0));
	if (!r_task->world->object_tree
		|| !r_task->world->object_tree->hit(
			r_task->world->object_tree, ray, &hrec, &range))
		return (r_task->world->ambient_light);
	if (!hrec.mat_ptr->scatter(hrec.mat_ptr, r_task, &hrec, &srec))
		return (srec.attenuation);
	if (is_killed_by_russian_roulette(depth, &srec.attenuation, &r_task->seed))
		return (fill_vec3(0.0));
	return (scal_mul_vec3(
			mul_vec3(
				srec.attenuation,
				compute_path_tracing_color(&srec.next_ray, r_task, depth + 1)),
			(srec.surface_pdf / srec.sampling_pdf)));
}

static bool	is_killed_by_russian_roulette(
		size_t depth,
		t_color *attenuation,
		uint64_t *seed)
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
	if (live_prob < random_01(seed))
		return (true);
	*attenuation = scal_div_vec3(*attenuation, live_prob);
	return (false);
}
