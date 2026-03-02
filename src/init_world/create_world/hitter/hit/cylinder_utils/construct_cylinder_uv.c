/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_cylinder_uv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:02:05 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/02 15:07:56 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "rt_define.h"

static t_vec2	construct_cylinder_uv(
	const t_vec3 *center_to_point,
	const t_vec3 *direct,
	double tmp_height,
	double height)
{
	const t_onb		onb = construct_onb(*direct);
	const double	theta = atan2(
			dot(*center_to_point, onb.v[0]),
			dot(*center_to_point, onb.v[1]));

	return (construct_vec2(
			1.0 - (theta / (2.0 * M_PI) + 0.5),
			tmp_height / height));
}
