/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_skips.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:12:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 02:59:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skip.h"

const t_skip			g_ambient_skips[] = {
	skip_lighting_ratio,
	skip_color,
	NULL
};

const t_skip			g_camera_skips[] = {
	skip_point,
	skip_unit,
	skip_angle,
	NULL
};

const t_skip			g_light_skips[] = {
	skip_point,
	skip_lighting_ratio,
	skip_color,
	NULL
};

const t_skip			g_sphere_skips[] = {
	skip_point,
	skip_length,
	skip_color,
	NULL
};

const t_skip			g_plane_skips[] = {
	skip_point,
	skip_unit,
	skip_color,
	NULL
};

const t_skip			g_cylinder_skips[] = {
	skip_point,
	skip_unit,
	skip_length,
	skip_length,
	skip_color,
	NULL
};

const t_skip			g_disk_skips[] = {
	skip_point,
	skip_unit,
	skip_length,
	skip_color,
	NULL
};

const t_skip			g_cone_skips[] = {
	skip_point,
	skip_unit,
	skip_sharp_angle,
	skip_color,
	NULL
};

const t_skip			g_triangle_skips[] = {
	skip_point,
	skip_point,
	skip_point,
	skip_color,
	NULL
};
