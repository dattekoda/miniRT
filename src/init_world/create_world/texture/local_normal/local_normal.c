/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:48:21 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/27 22:20:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <math.h>

t_vec3	local_normal_ripple(t_vec2 map)
{
	static const double	freq = 150 * M_PI;
	static const double	strength = 2.0;
	const double		r = sqrt(pow(map.e[0], 2) + pow(map.e[1], 2));
	const double		ripple = cos(r * freq) * strength;

	if (r == 0)
		return (construct_vec3(0, 0, 1.0));	
	return (construct_vec3(
			(map.e[0] / r) * ripple,
			(map.e[1] / r) * ripple,
			1.0));
}

t_vec3	local_normal_swirl(t_vec2 map)
{
	static const double	freq = 100.0;
	static const double	strength = 0.5;
	static const double	twist = 1.0;
	const double		r = sqrt(pow(map.e[0], 2) + pow(map.e[1], 2));
	const double		theta = atan2(map.e[1], map.e[0]) + r * twist;
	const double		height = sin(r * freq - theta);

	if (r == 0)
		return (construct_vec3(0, 0, 1));
	return (construct_vec3(
		cos(theta) * height * strength,
		sin(theta) * height * strength,
		1.0));
}

t_vec3	local_normal_interface(t_vec2 map)
{
	static const double	freq = 100.0 * M_PI;
	static const double	strength = 1.5;
	t_vec2				p1 = {0.2, 0.2};
	t_vec2				p2 = {-0.2, -0.2};
	const double		r1 = sqrt(pow(map.e[0] - p1.e[0], 2)
		+ pow(map.e[1] - p1.e[1], 2));
	const double		r2 = sqrt(pow(map.e[0] - p2.e[0], 2)
		+ pow(map.e[1] - p2.e[1], 2));
	const double		ripple = (cos(r1 * freq) + cos(r2 * freq)) * 0.5;

	return (construct_vec3(
		map.e[0] * ripple * strength,
		map.e[1] * ripple * strength,
		1.0));
}

t_vec3	local_normal_grid(t_vec2 map)
{
	static const double	scale = 2.3;
	static const double	sharpness = 0.3;
	const double		fx = map.e[0] * scale - floor(map.e[0] * scale);
	const double		fy = map.e[1] * scale - floor(map.e[1] * scale);
	t_vec2				dmap;

	if (fx > 0.5)
		dmap.e[0] = 1.0;
	else
		dmap.e[1] = -1.0;
	if (fy > 0.5)
		dmap.e[0] = 1.0;
	else
		dmap.e[1] = -1.0;
	return (construct_vec3(dmap.e[0] * sharpness, dmap.e[1] * sharpness, 1.0));
}
