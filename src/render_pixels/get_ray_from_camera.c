/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_from_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:03:16 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/07 21:57:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec_utils.h"
#include "camera.h"
#include "rt_utils.h"
#include "rt_define.h"

static t_vec3	random_point_in_unit_disk(void);

t_ray	get_ray_from_camera(const t_camera *camera, double u, double v)
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
				random_double(-1, 1),
				random_double(-1, 1),
				0);
		if (length_squared_vec3(random_point) < 1)
			break ;
	}
	return (random_point);
}
