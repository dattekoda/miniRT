/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:12:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/21 15:02:53 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "line_to_element.h"
#include "init_world_define.h"
#include "solid_texture.h"
#include "lambertian.h"
#include "rt_config.h"

int	line_to_light(t_hitter **light, const char *line);
int	line_to_disk(t_hitter **disk, const char *line);

static const t_skip			g_ambient_skips[] = {
	skip_lighting_ratio,
	skip_color,
	skip_until_end,
	NULL
};

const t_element				g_ambient_info = {
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

const t_element				g_camera_info = {
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

const t_element				g_light_info = {
	.id = "L",
	.id_len = 1,
	.format = \
"L [coordinate](x,y,z) [light brightness ratio](0-1) [R,G,B](0-255)",
	.skip_arr = g_light_skips,
	.line_to_hitter = line_to_light
};

static const t_skip			g_sphere_skips[] = {
	skip_point,
	skip_length,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element		g_sphere_info = {
	.id = "sp",
	.id_len = 2,
	.format = "sp [coordinate](x,y,z) [diameter](>0) [R,G,B](0-255)",
	.skip_arr = g_sphere_skips,
	.line_to_hitter = line_to_sphere,
	.material_id = SPHERE_MATERIAL_ID,
	.texture_id = SPHERE_TEXTURE_ID
};

static const t_skip			g_plane_skips[] = {
	skip_point,
	skip_unit,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element		g_plane_info = {
	.id = "pl",
	.id_len = 2,
	.format = "pl [coordinate](x,y,z) [normalized orient vector](0-1) \
[R,G,B](0-255)",
	.skip_arr = g_plane_skips,
	.line_to_hitter = NULL,
	.material_id = PLANE_MATERIAL_ID,
	.texture_id = PLANE_TEXTURE_ID
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

static const t_element		g_cylinder_info = {
	.id = "cy",
	.id_len = 2,
	.format = "cy [coordinate](x,y,z) [normalized orient vector](0-1) \
[diameter](>0) [height](>0) [R,G,B](0-255)",
	.skip_arr = g_cylinder_skips,
	.line_to_hitter = NULL,
	.material_id = CYLINDER_MATERIAL_ID,
	.texture_id = CYLINDER_TEXTURE_ID
};

static const t_skip			g_disk_skips[] = {
	skip_point,
	skip_unit,
	skip_length,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element		g_disk_info = {
	.id = "di",
	.id_len = 2,
	.format = "di [coordinate](x,y,z) [normalized orient vector](0-1) \
[diameter](>0) [R,G,B](0-255)",
	.skip_arr = g_disk_skips,
	.line_to_hitter = line_to_disk,
	.material_id = CYLINDER_MATERIAL_ID,
	.texture_id = CYLINDER_TEXTURE_ID
};

static const t_skip			g_cone_skips[] = {
	skip_point,
	skip_unit,
	skip_sharp_angle,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element		g_cone_info = {
	.id = "co",
	.id_len = 2,
	.format = "co [coordinate](x,y,z) [normalized orient vector](0-1) \
[angle](0-90) [R,G,B](0-255)",
	.skip_arr = g_cone_skips,
	.line_to_hitter = NULL,
	.material_id = CONE_MATERIAL_ID,
	.texture_id = CONE_TEXTURE_ID
};

static const t_skip			g_triangle_skips[] = {
	skip_point,
	skip_point,
	skip_point,
	skip_color,
	skip_until_end,
	NULL
};

static const t_element		g_triangle_info = {
	.id = "tr",
	.id_len = 2,
	.format = "tr [coordinate](x,y,z) [coordinate](x,y,z) [coordinate](x,y,z) \
[R,G,B](0-255)",
	.skip_arr = g_triangle_skips,
	.line_to_hitter = NULL,
	.material_id = TRIANGLE_MATERIAL_ID,
	.texture_id = TRIANGLE_TEXTURE_ID
};

/*
@param NULL終端にするためにポインタの配列にしている。
*/
const t_element				*g_info_table[] = {
	&g_ambient_info,
	&g_camera_info,
	&g_light_info,
	&g_sphere_info,
	&g_plane_info,
	&g_cylinder_info,
	&g_disk_info,
	&g_cone_info,
	&g_triangle_info,
	NULL
};

const t_element				*g_infinite_table[] = {
	&g_plane_info,
	&g_cone_info,
	NULL
};

const t_element				*g_finite_table[] = {
	&g_sphere_info,
	&g_cylinder_info,
	&g_disk_info,
	&g_triangle_info,
	&g_light_info,
	NULL
};

const t_generate_texture	g_generate_textures[] = {
	generate_solid_texture,
	NULL
};

const t_generate_material	g_generate_materials[] = {
	generate_lambertian,
	NULL
};
