/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:53:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 19:11:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "rt_config.h"
#include "rt_define.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include <stdbool.h>
#include <assert.h>

t_camera		get_camera_data(const char *line);
static bool		camera_equal(t_camera a, t_camera b);
bool			vec3_equal(t_vec3 a, t_vec3 b);

int	test_get_camera_data(void)
{
	static const double hfov70_width = 1.4004150764; // tan((hfov*M_PI/180) / 2) * 2
	// カメラのonb座標設定確認要
	assert(camera_equal(get_camera_data("C 50.0,0,20 0,0,1 70"), (t_camera){
		.origin = (t_point3){{50.0,0,20}},
		.onb = (t_onb){(t_vec3){{1, 0, 0}}, (t_vec3){{0, 1, 0}}, (t_vec3){{0, 0, 1}}},
		.screen_width = hfov70_width,
		.screen_height = hfov70_width * ASPECT_RATIO,
		.left_top = add_vec3((t_point3){{50.0,0,20}}, (t_vec3){{-hfov70_width / 2, hfov70_width * ASPECT_RATIO / 2, 1}})
	}));
	return (0);
}

void	print_vec(t_vec3 v);

static bool	camera_equal(t_camera a, t_camera b)
{
	if (!vec3_equal(a.origin, b.origin))
	{
		return (false);
	}
	if (!vec3_equal(a.onb.v[0], b.onb.v[0]))
	{
		return (false);
	}
	if (!vec3_equal(a.onb.v[1], b.onb.v[1]))
	{
		return (false);
	}
	if (!vec3_equal(a.onb.v[2], b.onb.v[2]))
	{
		return (false);
	}
	if (!fequal(a.screen_width, b.screen_width))
	{
		return (false);
	}
	if (!fequal(a.screen_height, b.screen_height))
	{
		return (false);
	}
	if (!vec3_equal(a.left_top, b.left_top))
	{
		return (false);
	}
	return (true);
}
