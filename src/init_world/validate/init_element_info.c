/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:39:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 01:49:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"

static const t_skip			g_ambient_skips[] = {
	skip_spaces,
	skip_lighting_ratio,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

const t_element_info		g_ambient_info = {
	.id = "A",
	.id_len = 1,
	.format = "A [lighting ratio(0-1)] [R,G,B(0-255)]",
	.skip_arr = g_ambient_skips
};

static const t_skip			g_camera_skips[] = {
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_unit,
	skip_spaces,
	skip_fov,
	skip_until_end,
	NULL
};

const t_element_info		g_camera_info = {
	.id = "C",
	.id_len = 1,
	.format = \
"C [coordinate](x,y,z) [normalized orient vector](a,b,c) [fov](0-180)",
	.skip_arr = g_camera_skips
};

static const t_skip			g_light_skips[] = {
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_lighting_ratio,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element_info	g_light_info = {
	.id_len = 1,
	.format = \
"L [coordinate](x,y,z) [light brightness ratio](0-1) [R,G,B](0-255)",
	.skip_arr = g_light_skips
};

static const t_skip			g_sphere_skips[] = {
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_diameter,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element_info	g_sphere_info = {
	.id = "sp",
	.id_len = 2,
	.format = "sp [coordinate](x,y,z) [diameter](>0) [R,G,B](0-255)",
	.skip_arr = g_sphere_skips
};

const t_element_info		*g_info_table[] = {
	&g_ambient_info,
	&g_camera_info,
	&g_light_info,
	&g_sphere_info,
	NULL
};
