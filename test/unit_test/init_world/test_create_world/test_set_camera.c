/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:53:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 15:09:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "rt_config.h"
#include "rt_define.h"
#include "vec_utils.h"
#include <stdbool.h>
#include <assert.h>

static int		test_get_camera_data(void);
static t_camera	get_camera_data(const char *line);
static bool		camera_equal(t_camera a, t_camera b);

int	test_set_camera(void)
{
	test_get_camera_data();
	return (0);
}

#define HFOV70_WIDTH 1.4004150764 // tan((hfov*M_PI/180) / 2) * 2

static int	test_get_camera_data(void)
{
	assert(camera_equal(get_camera_data("C -50.0,0,20 0,0,1 70"), (t_camera){
		.origin = (t_point3){{-50.0,0,20}},
		.onb = (t_onb){{{1, 0, 0}}, {{0, 1, 0}}, {{0, 0, -1}}},
		.screen_width = HFOV70_WIDTH,
		.screen_height = HFOV70_WIDTH * ASPECT_RATIO,
		.left_top = add_vec3((t_point3){{-50.0,0,20}}, (t_vec3){{HFOV70_WIDTH, HFOV70_WIDTH * ASPECT_RATIO, 0}})
	}));
	return (0);
}

static bool	camera_equal(t_camera a, t_camera b)
{
	return (false);
}
