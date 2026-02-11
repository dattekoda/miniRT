/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sample_pixel_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:51:41 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/11 21:00:56 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "vec_utils.h"
#include "libft.h"
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
					int xi,
					int yi,
					const t_world *world,
					bool is_phong);
static void		calc_uv(double *u, double *v, int xi, int yi);
static t_vec3	random_point_in_unit_disk(void);
static t_ray	get_ray_from_camera(
					const t_camera *camera,
					double u,
					double v);

t_color	calc_sample_pixel_color(
					int xi,
					int yi,
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

// TODO: u, v should be t_vec2 map
static t_color	calc_one_sample_pixel_color(
					int xi,
					int yi,
					const t_world *world,
					bool is_phong)
{
	t_ray	ray;
	double	u;
	double	v;

	calc_uv(&u, &v, xi, yi);
	ray = get_ray_from_camera(&world->camera, u, v);
	if (is_phong)
		return (compute_phong_color(&ray, world));
	return (compute_path_tracing_color(&ray, world, 0));
}

static void	calc_uv(double *u, double *v, int xi, int yi)
{
	static const double	inv_w = 1.0 / (WINDOW_WIDTH - 1);
	static const double	inv_h = 1.0 / (WINDOW_WIDTH * ASPECT_RATIO - 1);
	
	*u = (xi + random_01()) * inv_w;
	*v = (yi + random_01()) * inv_h;
	return ;
}

// TODO: maybe necessary to normalize ray's vector
static t_ray	get_ray_from_camera(const t_camera *camera, double u, double v)
{
	t_vec3				ray_displacement;
	t_vec3				offset;
	t_vec3				ray_direct;

	ray_displacement
		= scal_mul_vec3(random_point_in_unit_disk(), LENS_RADIUS);
	offset = add_vec3(
			scal_mul_vec3(camera->onb.v[0], ray_displacement.e[0]),
			scal_mul_vec3(camera->onb.v[1], ray_displacement.e[1]));
	ray_direct = sub_vec3(
			add_vec3(camera->left_top, scal_mul_vec3(camera->onb.v[0], u)),
			add_vec3(scal_mul_vec3(camera->onb.v[1], v), camera->origin));
	return (construct_ray(
			add_vec3(camera->origin, offset),
			sub_vec3(ray_direct, offset)));
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
