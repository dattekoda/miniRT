/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:53:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 13:44:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <stdbool.h>
#include <assert.h>

static int	test_get_camera_data(void);
static t_camera	get_camera_data(const char *line);
static bool	camera_equal(t_camera a, t_camera b);

int	test_set_camera(void)
{
	test_get_camera_data();
	return (0);
}

static int	test_get_camera_data(void)
{
	assert(camera_equal(get_camera_data("C -50.0,0,20 0,0,1 70"), (t_camera){
		.origin = (t_point3){{-50.0,0,20}},
		.onb = (t_onb){{{0, 0, 1}}, {0, 1, 0}, {1, 0, 0}},
		
	}));
	return (0);
}

static bool	camera_equal(t_camera a, t_camera b)
{
	return (false);
}
