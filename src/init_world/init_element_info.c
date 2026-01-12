/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:39:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 14:18:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"

static const t_skip			g_ambient_skips[] = {
	skip_lighting_ratio,
	skip_color,
	skip_until_end,
	NULL
};

const t_element_info		g_ambient_info = {
	.type = AMBIENT,
	.id = "A",
	.id_len = 1,
	.format = "A [lighting ratio(0-1)] [R,G,B(0-255)]",
	.skip_arr = g_ambient_skips
};

static const t_skip			g_camera_skips[] = {
	skip_point,
	skip_unit,
	skip_angle,
	skip_until_end,
	NULL
};

const t_element_info		g_camera_info = {
	.type = CAMERA,
	.id = "C",
	.id_len = 1,
	.format = \
"C [coordinate](x,y,z) [normalized orient vector](a,b,c) [fov](0-180)",
	.skip_arr = g_camera_skips
};

static const t_skip			g_light_skips[] = {
	skip_point,
	skip_lighting_ratio,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element_info	g_light_info = {
	.type = LIGHT,
	.id = "L",
	.id_len = 1,
	.format = \
"L [coordinate](x,y,z) [light brightness ratio](0-1) [R,G,B](0-255)",
	.skip_arr = g_light_skips
};

static const t_skip			g_sphere_skips[] = {
	skip_point,
	skip_length,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element_info	g_sphere_info = {
	.type = SPHERE,
	.id = "sp",
	.id_len = 2,
	.format = "sp [coordinate](x,y,z) [diameter](>0) [R,G,B](0-255)",
	.skip_arr = g_sphere_skips
};

static const t_skip			g_plane_skips[] = {
	skip_point,
	skip_unit,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element_info	g_plane_info = {
	.type = PLANE,
	.id = "pl",
	.id_len = 2,
	.format = "pl [coordinate](x,y,z) [normalized orient vector](0-1) \
[R,G,B](0-255)",
	.skip_arr = g_plane_skips
};

static const t_skip			g_cylinder_skips[] = {
	skip_point,
	skip_unit,
	skip_length,
	skip_length,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element_info	g_cylinder_info = {
	.type = CYLINDER,
	.id = "cy",
	.id_len = 2,
	.format = "cy [coordinate](x,y,z) [normalized orient vector](0-1) \
[diameter](>0) [height](>0) [R,G,B](0-255)",
	.skip_arr = g_cylinder_skips
};

static const t_skip			g_cone_skips[] = {
	skip_point,
	skip_unit,
	skip_sharp_angle,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element_info	g_cone_info = {
	.type = CONE,
	.id = "co",
	.id_len = 2,
	.format = "co [coordinate](x,y,z) [normalized orient vector](0-1) \
[angle](0-90) [R,G,B](0-255)",
	.skip_arr = g_cone_skips
};

static const t_skip			g_triangle_skips[] = {
	skip_point,
	skip_point,
	skip_point,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element_info	g_triangle_info = {
	.type = TRIANGLE,
	.id = "tr",
	.id_len = 2,
	.format = "tr [coordinate](x,y,z) [coordinate](x,y,z) [coordinate](x,y,z) \
[R,G,B](0-255)",
	.skip_arr = g_triangle_skips
};

const t_element_info		*g_info_table[] = {
	&g_ambient_info,
	&g_camera_info,
	&g_light_info,
	&g_sphere_info,
	&g_plane_info,
	&g_cylinder_info,
	&g_cone_info,
	&g_triangle_info,
	NULL
};

const t_element_info		*g_infinte_table[] = {
	&g_plane_info,
	&g_cone_info,
	NULL
};

const t_element_info		*g_finte_table[] = {
	&g_sphere_info,
	&g_cylinder_info,
	&g_triangle_info,
	NULL
};
