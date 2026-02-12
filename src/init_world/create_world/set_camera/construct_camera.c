/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:20:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 22:15:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vec_utils.h"
#include "rt_config.h"
#include "rt_define.h"
#include "axis.h"
#include <math.h>

static t_onb	construct_camera_onb(t_vec3 direct);
static void		calc_screen_size(double hfov, double *width, double *height);
static t_vec3	calc_screen_left_top(
					t_vec3 origin, t_onb onb, double width, double height);

t_camera	construct_camera(t_point3 origin, t_vec3 direct, double hfov)
{
	t_camera	camera;

	camera.origin = origin;
	camera.onb = construct_camera_onb(direct);
	calc_screen_size(hfov, &camera.width, &camera.height);
	camera.left_top = calc_screen_left_top(
			camera.origin, camera.onb, camera.width, camera.height);
	return (camera);
}

static t_vec3	calc_screen_left_top(
					t_vec3 origin, t_onb onb, double width, double height)
{
	t_vec3	left_top;

	left_top = sub_vec3(origin, scal_mul_vec3(onb.v[A_X], 0.5 * width));
	left_top = add_vec3(left_top, scal_mul_vec3(onb.v[A_Y], 0.5 * height));
	left_top = add_vec3(left_top, normalize(onb.v[A_Z]));
	return (left_top);
}

static t_onb	construct_camera_onb(t_vec3 direct)
{
	t_onb	camera_onb;
	t_vec3	vup;

	if (fabs(direct.e[A_Y]) > 0.9)
		vup = construct_vec3(0, 1, 0);
	else
		vup = construct_vec3(0, 0, 1);
	camera_onb.v[A_Z] = direct;
	camera_onb.v[A_X] = normalize(cross(vup, camera_onb.v[A_Z]));
	camera_onb.v[A_Y] = cross(camera_onb.v[A_Z], camera_onb.v[A_X]);
	return (camera_onb);
}

static void	calc_screen_size(double hfov, double *width, double *height)
{
	const double	hfov_radian = (hfov / 180) * M_PI;

	*width = tan(hfov_radian * 0.5) * 2.0;
	*height = *width * ASPECT_RATIO;
	return ;
}
