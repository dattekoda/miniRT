/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sample_pixel_color_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:51:41 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 23:17:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_bonus.h"
#include "render_task_bonus.h"
#include "vec_utils_bonus.h"
#include "libft.h"
#include "axis_bonus.h"
#include "option_bonus.h"
#include "rt_utils_bonus.h"
#include "rt_define_bonus.h"

t_color			compute_phong_color(
					const t_ray *ray,
					t_render_task *r_task);
t_color			compute_path_tracing_color(
					const t_ray *ray,
					t_render_task *r_task,
					size_t depth);
static t_color	calc_one_sample_pixel_color(
					t_render_task *r_task,
					size_t xi,
					size_t yi);
static t_vec2	calc_random_xy(uint64_t *seed, size_t xi, size_t yi);
static t_vec3	random_point_in_unit_disk(uint64_t *seed);
static t_ray	get_ray_from_camera(
					const t_camera *camera,
					uint64_t *seed,
					size_t xi,
					size_t yi);

t_color	accumulate_sample_pixel_color(
			t_render_task *r_task,
			size_t xi,
			size_t yi)
{
	static const double	color_scale = 1.0 / SAMPLES_PER_PIXEL;
	size_t				si;
	t_color				pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	si = 0;
	while (si < SAMPLES_PER_PIXEL)
	{
		pixel_color
			= add_vec3(
				pixel_color,
				calc_one_sample_pixel_color(r_task, xi, yi));
		si++;
	}
	return (scal_mul_vec3(pixel_color, color_scale));
}

static t_color	calc_one_sample_pixel_color(
					t_render_task *r_task,
					size_t xi,
					size_t yi)
{
	const t_ray	ray
		= get_ray_from_camera(&r_task->world->camera, &r_task->seed, xi, yi);

	if (r_task->is_phong)
		return (compute_phong_color(&ray, r_task));
	return (compute_path_tracing_color(&ray, r_task, 0));
}

static t_ray	get_ray_from_camera(
					const t_camera *camera,
					uint64_t *seed,
					size_t xi,
					size_t yi)
{
	const t_vec2	random_xv = calc_random_xy(seed, xi, yi);
	const t_vec3	ray_displacement
		= scal_mul_vec3(random_point_in_unit_disk(seed), LENS_RADIUS);
	const t_vec3	offset
		= add_vec3(
			scal_mul_vec3(camera->onb.v[A_X], ray_displacement.e[A_X]),
			scal_mul_vec3(camera->onb.v[A_Y], ray_displacement.e[A_Y]));
	const t_vec3	ray_direct
		= sub_vec3(
			add_vec3(
				camera->left_top,
				scal_mul_vec3(camera->onb.v[A_X],
					random_xv.e[A_X] * camera->width)),
			add_vec3(
				scal_mul_vec3(camera->onb.v[A_Y],
					random_xv.e[A_Y] * camera->height),
				camera->origin));

	return (construct_ray(
			add_vec3(camera->origin, offset),
			(sub_vec3(ray_direct, offset))));
}

static t_vec2	calc_random_xy(uint64_t *seed, size_t xi, size_t yi)
{
	static const double	inv_w = 1.0 / (WINDOW_WIDTH - 1);
	static const double	inv_h = 1.0 / (WINDOW_WIDTH * ASPECT_RATIO - 1);

	return (construct_vec2(
			(xi + random_01(seed)) * inv_w,
			(yi + random_01(seed)) * inv_h));
}

static t_vec3	random_point_in_unit_disk(uint64_t *seed)
{
	t_vec3	random_point;

	while (true)
	{
		random_point = construct_vec3(
				random_minus1_to_1(seed),
				random_minus1_to_1(seed),
				0);
		if (length_squared_vec3(random_point) < 1.0)
			break ;
	}
	return (random_point);
}
