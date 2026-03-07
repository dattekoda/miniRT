/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_plane_uv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:51:22 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/07 18:06:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>

t_point2	construct_plane_uv(
					const t_vec3 *normal,
					const t_vec3 *hit_point,
					const t_vec3 *plane_point)
{
	static const double	inv_unit_edge = 1 / (double)(UNIT_EDGE * 10.0);
	const t_vec3		offset = sub_vec3(*hit_point, *plane_point);
	const t_onb			onb = construct_onb(*normal);
	t_point2			map;

	map = construct_vec2(
			dot(offset, onb.v[0]) * inv_unit_edge,
			dot(offset, onb.v[1]) * inv_unit_edge);
	map.e[0] = map.e[0] - floor(map.e[0]);
	map.e[1] = map.e[1] - floor(map.e[1]);
	return (map);
}
