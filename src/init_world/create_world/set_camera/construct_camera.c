/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:20:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:40:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vec_utils.h"
#include "rt_config.h"
#include "rt_define.h"
#include <math.h>

static t_onb	construct_camera_onb(t_vec3 direct);
static void		get_screen_size(double hfov, double *width, double *height);

t_camera	construct_camera(t_point3 origin, t_vec3 direct, double hfov)
{
	t_camera	camera;

	camera.origin = origin;
	camera.onb = construct_camera_onb(direct);
	get_screen_size(hfov, &camera.screen_width, &camera.screen_height);
	camera.heigh_left = add_vec3(origin,
			add_vec3(scal_mul_vec3(camera.onb.v[0],
					camera.screen_width * 0.5),
				scal_mul_vec3(camera.onb.v[2],
					camera.screen_height * 0.5)));
	return (camera);
}

static t_onb	construct_camera_onb(t_vec3 direct)
{
	t_onb	camera_onb;
	t_vec3	vup;

	if (fabs(direct.e[1]) > 0.9)
		vup = construct_vec3(1, 0, 0);
	else
		vup = construct_vec3(0, 1, 0);
	camera_onb.v[2] = negative_vec3(direct);
	camera_onb.v[0] = normalize(cross(vup, camera_onb.v[2]));
	camera_onb.v[1] = cross(camera_onb.v[2], camera_onb.v[0]);
	return (camera_onb);
}

static void	get_screen_size(double hfov, double *width, double *height)
{
	double	theta;

	theta = hfov * M_PI / 180.0;
	*width = tan(theta) * 2.0;
	*height = *width * ASPECT_RATIO;
}
