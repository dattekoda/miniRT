/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_normal_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:48:21 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils_bonus.h"
#include "rt_define_bonus.h"
#include "libft.h"
#include <math.h>

t_vec3	local_normal_ripple(t_vec2 map)
{
	const double	frequency = 150 * M_PI;
	const double	strength = 2.0;
	const double	r = sqrt(pow(map.e[0], 2) + pow(map.e[1], 2));
	const double	ripple = cos(r * frequency) * strength;

	if (r == 0)
		return (construct_vec3(0, 0, 1.0));
	return (construct_vec3(
			(map.e[0] / r) * ripple,
			(map.e[1] / r) * ripple,
			1.0));
}

#define BLOCK_THICKNESS 0.05
#define BLOCK_STRENGTH 2.0
#define BLOCK_WIDTH 20.0
#define BLOCK_HEIGHT 10.0

t_vec3	local_normal_block(t_vec2 map)
{
	const int	row = (int)floor(map.e[1] / BLOCK_HEIGHT);
	t_vec2		cycle_map;
	t_vec2		delta_map;

	if (row % 2 != 0)
		map.e[0] += BLOCK_WIDTH / 2.0;
	cycle_map = construct_vec2(
			map.e[0] - floor(map.e[0] / BLOCK_WIDTH * BLOCK_WIDTH),
			map.e[1] - floor(map.e[1] / BLOCK_HEIGHT * BLOCK_HEIGHT));
	ft_bzero(&delta_map, sizeof(t_vec2));
	if (cycle_map.e[0] < BLOCK_THICKNESS)
		delta_map.e[0] = -BLOCK_STRENGTH;
	else if (cycle_map.e[0] > BLOCK_WIDTH - BLOCK_THICKNESS)
		delta_map.e[1] = BLOCK_STRENGTH;
	if (cycle_map.e[1] < BLOCK_THICKNESS)
		delta_map.e[0] = -BLOCK_STRENGTH;
	else if (cycle_map.e[1] > BLOCK_HEIGHT - BLOCK_THICKNESS)
		delta_map.e[1] = BLOCK_STRENGTH;
	return (construct_vec3(delta_map.e[0], delta_map.e[1], 1.0));
}
