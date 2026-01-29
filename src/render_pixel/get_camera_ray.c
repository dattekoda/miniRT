/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:35:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 19:35:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "camera.h"
#include "vec_utils.h"
#include "rt_config.h"
#include "rt_utils.h"

static t_vec3	calc_ray_direct(const t_camera *camera, double u, double v);
static t_vec3	random_in_unit_disk(void);

/*
@param u スクリーンの左上からどれくらい右か[0-1]
@param v スクリーンの左上からどれくらい下か[0-1]
*/
t_ray	get_camera_ray(const t_camera *camera, double u, double v)
{
	t_ray	ray;
	t_vec3	random_disk;
	t_vec3	offset;
	t_vec3	ray_direct;

	random_disk = scal_mul_vec3(random_in_unit_disk(), LENS_RADIUS);
	offset = add_vec3(scal_mul_vec3(camera->onb.v[0], random_disk.e[0]),
			scal_mul_vec3(camera->onb.v[1], random_disk.e[1]));
	ray_direct = calc_ray_direct(camera, u, v);
	ray = construct_ray(add_vec3(camera->origin, offset),
			sub_vec3(ray_direct, offset));
	return (ray);
}

static t_vec3	calc_ray_direct(const t_camera *camera, double u, double v)
{
	t_vec3	to_left_top;
	t_vec3	horizonal;
	t_vec3	vertical;

	to_left_top = sub_vec3(camera->left_top, camera->origin);
	horizonal = scal_mul_vec3(camera->onb.v[0], camera->width * u);
	vertical = scal_mul_vec3(camera->onb.v[2], camera->height * (-v));
	return (add_vec3(to_left_top, add_vec3(horizonal, vertical)));
}

static t_vec3	random_in_unit_disk(void)
{
	t_vec3	vec;

	while (1)
	{
		vec = construct_vec3(random_double(-1, 1), random_double(-1, 1), 0);
		if (length_squared_vec3(vec) < 1)
			break ;
	}
	return (vec);
}
