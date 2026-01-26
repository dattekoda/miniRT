/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:12:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 21:17:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "line_to_element.h"
#include "init_world_define.h"
#include "solid_texture.h"
#include "lambertian.h"
#include "option.h"
#include "rt_config.h"

int	line_to_light(t_hitter **light, const char *line);
int	line_to_disk(t_hitter **disk, const char *line);

extern const t_skip	g_ambient_skips[];
extern const t_skip	g_camera_skips[];
extern const t_skip	g_light_skips[];
extern const t_skip	g_sphere_skips[];
extern const t_skip	g_plane_skips[];
extern const t_skip	g_cylinder_skips[];
extern const t_skip	g_disk_skips[];
extern const t_skip	g_cone_skips[];
extern const t_skip	g_ambient_skips[];
extern const t_skip	g_triangle_skips[];

const t_element				g_ambient_info = {
	.id = "A",
	.id_len = 1,
	.input_format = "A [lighting ratio(0-1)] [R,G,B(0-255)]",
	.skip_arr = g_ambient_skips,
	.line_to_hitter = NULL
};

const t_element				g_camera_info = {
	.id = "C",
	.id_len = 1,
	.input_format = \
"C [coordinate](x,y,z) [normalized orient vector](a,b,c) [fov](0-180)",
	.skip_arr = g_camera_skips
};

const t_element				g_light_info = {
	.id = "L",
	.id_len = 1,
	.input_format = \
"L [coordinate](x,y,z) [light brightness ratio](0-1) [R,G,B](0-255)",
	.skip_arr = g_light_skips,
	.line_to_hitter = line_to_light
};

const t_element		g_sphere_info = {
	.id = "sp",
	.id_len = 2,
	.input_format = "sp [coordinate](x,y,z) [diameter](>0) [R,G,B](0-255)",
	.skip_arr = g_sphere_skips,
	.line_to_hitter = line_to_sphere
};

const t_element		g_plane_info = {
	.id = "pl",
	.id_len = 2,
	.input_format = "pl [coordinate](x,y,z) [normalized orient vector](0-1) \
[R,G,B](0-255)",
	.skip_arr = g_plane_skips,
	.line_to_hitter = NULL
};

const t_element		g_cylinder_info = {
	.id = "cy",
	.id_len = 2,
	.input_format = "cy [coordinate](x,y,z) [normalized orient vector](0-1) \
[diameter](>0) [height](>0) [R,G,B](0-255)",
	.skip_arr = g_cylinder_skips,
	.line_to_hitter = NULL
};

const t_element		g_disk_info = {
	.id = "di",
	.id_len = 2,
	.input_format = "di [coordinate](x,y,z) [normalized orient vector](0-1) \
[diameter](>0) [R,G,B](0-255)",
	.skip_arr = g_disk_skips,
	.line_to_hitter = line_to_disk
};

const t_element		g_cone_info = {
	.id = "co",
	.id_len = 2,
	.input_format = "co [coordinate](x,y,z) [normalized orient vector](0-1) \
[angle](0-90) [R,G,B](0-255)",
	.skip_arr = g_cone_skips,
	.line_to_hitter = NULL
};

const t_element		g_triangle_info = {
	.id = "tr",
	.id_len = 2,
	.input_format = "tr [coordinate](x,y,z) [coordinate](x,y,z) [coordinate](x,y,z) \
[R,G,B](0-255)",
	.skip_arr = g_triangle_skips,
	.line_to_hitter = NULL
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
	// &g_plane_info,
	// &g_cone_info,
	NULL
};

const t_element				*g_finite_table[] = {
	&g_light_info,
	&g_sphere_info,
	// &g_cylinder_info,
	// &g_disk_info,
	// &g_triangle_info,
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
