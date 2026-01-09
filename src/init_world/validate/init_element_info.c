/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:39:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 01:07:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"

const t_skip	ambient_skips[] = {
	skip_spaces,
	skip_lighting_ratio,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

const t_element_info ambient_info = 
{
	.identifer = "A",
	.identifier_len = 1,
	.format = "A [lighting ratio(0-1)] [R,G,B(0-255)]",
	.skip_arr = ambient_skips
};

const t_skip	camera_skips[] =
{
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_unit,
	skip_spaces,
	skip_fov,
	skip_until_end,
	NULL
};

const t_element_info	camera_info =
{
	.identifer = "C",
	.identifier_len = 1,
	.format = \
"C [coordinate](x,y,z) [normalized orient vector](a,b,c) [fov](0-180)",
	.skip_arr = camera_skips
};

const t_skip	light_skips[] =
{
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_lighting_ratio,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

const t_element_info	light_info =
{
	.identifier_len = 1,
	.format = \
"L [coordinate](x,y,z) [light brightness ratio](0-1) [R,G,B](0-255)",
	.skip_arr = light_skips
};

const t_skip	sphere_skips[] =
{
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_diameter,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

const t_element_info	sphere_info =
{
	.identifer = "sp",
	.identifier_len = 2,
	.format = "sp [coordinate](x,y,z) [diameter](>0) [R,G,B](0-255)",
	.skip_arr = sphere_skips
};

const t_element_info	*info_table[] = 
{
	&ambient_info,
	&camera_info,
	&light_info,
	&sphere_info,
	NULL
};
