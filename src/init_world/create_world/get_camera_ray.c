/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:35:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 16:25:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "camera.h"
#include "vec_utils.h"
#include "rt_config.h"
#include "rt_utils.h"

static t_vec3	calc_ray_direction(const t_camera *camera, double u, double v);
t_ray			construct_ray(t_point3 ori, t_vec3 dir);

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
	ray_direct = calc_ray_direction(camera, u, v);
	ray = construct_ray(add_vec3(camera->origin, offset), 
			sub_vec3(ray_direct, offset));
	return (ray);
}

static t_vec3	calc_ray_direction(const t_camera *camera, double u, double v)
{
	t_vec3	to_heigher_left;
	t_vec3	horizonal;
	t_vec3	vertical;

	to_heigher_left = sub_vec3(camera->heigher_left, camera->origin);
	horizonal = scal_mul_vec3(camera->onb.v[0], camera->screen_width * -u);
	vertical = scal_mul_vec3(camera->onb.v[2], camera->screen_height * -v);
	return (add_vec3(to_heigher_left, add_vec3(horizonal, vertical)));
}
