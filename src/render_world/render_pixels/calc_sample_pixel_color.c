/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sample_pixel_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:51:41 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/12 23:11:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "vec_utils.h"
#include "libft.h"
#include "axis.h"
#include "option.h"
#include "rt_utils.h"
#include "rt_define.h"

t_color			compute_phong_color(
					const t_ray *ray,
					const t_world *world);
t_color			compute_path_tracing_color(
					const t_ray *ray,
					const t_world *world,
					size_t depth);
static t_color	calc_one_sample_pixel_color(
					size_t xi,
					size_t yi,
					const t_world *world,
					bool is_phong);
static t_vec2	calc_random_xv(size_t xi, size_t yi);
static t_vec3	random_point_in_unit_disk(void);
static t_ray	get_ray_from_camera(
					const t_camera *camera,
					size_t xi,
					size_t yi);

t_color	calc_sample_pixel_color(
			size_t xi,
			size_t yi,
			const t_world *world,
			bool is_phong)
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
				calc_one_sample_pixel_color(xi, yi, world, is_phong));
		si++;
	}
	return (scal_mul_vec3(pixel_color, color_scale));
}

#include "rt_debug.h"
#include <stdlib.h>
static t_color	calc_one_sample_pixel_color(
					size_t xi,
					size_t yi,
					const t_world *world,
					bool is_phong)
{
	const t_ray		ray = get_ray_from_camera(&world->camera, xi, yi);

	if (is_phong)
		return (compute_phong_color(&ray, world));
	return (compute_path_tracing_color(&ray, world, 0));
}

#include <stdio.h>
// TODO: maybe need to normalize ray's vector
static t_ray	get_ray_from_camera(const t_camera *camera, size_t xi, size_t yi)
{
	const t_vec2	random_xv = calc_random_xv(xi, yi);
	const t_vec3	ray_displacement
		= scal_mul_vec3(random_point_in_unit_disk(), LENS_RADIUS);
	const t_vec3	offset = add_vec3(
			scal_mul_vec3(camera->onb.v[0], ray_displacement.e[0]),
			scal_mul_vec3(camera->onb.v[1], ray_displacement.e[1]));
	const t_vec3	ray_direct = sub_vec3(
			add_vec3(camera->left_top, scal_mul_vec3(camera->onb.v[A_X], random_xv.e[A_X])),
			add_vec3(scal_mul_vec3(camera->onb.v[A_Y], random_xv.e[A_Y]), camera->origin));

	return (construct_ray(
			add_vec3(camera->origin, offset),
			normalize(sub_vec3(ray_direct, offset))));
}

static t_vec2	calc_random_xv(size_t xi, size_t yi)
{
	static const double	inv_w = 1.0 / (WINDOW_WIDTH - 1);
	static const double	inv_h = 1.0 / (WINDOW_WIDTH * ASPECT_RATIO - 1);
	
	return (construct_vec2(
			(xi + random_01()) * inv_w,
			(yi + random_01()) * inv_h));
}

static t_vec3	random_point_in_unit_disk(void)
{
	t_vec3	random_point;

	while (true)
	{
		random_point = construct_vec3(
			random_minus1_to_1(),
			random_minus1_to_1(),
			0);
		if (length_squared_vec3(random_point) < 1.0)
			break ;
	}
	return (random_point);
}
