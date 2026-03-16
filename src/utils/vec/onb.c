/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 22:10:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 17:56:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "vec.h"
#include "axis.h"
#include <math.h>

t_onb	construct_onb(const t_vec3 vec3)
{
	t_onb	onb;
	t_vec3	operand;

	onb.v[2] = normalize_vec3(vec3);
	if (fabs(onb.v[2].e[A_X]) > 0.9)
		operand = construct_vec3(0, 1, 0);
	else
		operand = construct_vec3(1, 0, 0);
	onb.v[1] = normalize_vec3(cross(onb.v[2], operand));
	onb.v[0] = cross(onb.v[2], onb.v[1]);
	return (onb);
}

/*
@brief x * u + y * v + z * w
*/
t_vec3	local_onb(t_onb onb, t_vec3 vec3)
{
	return (add_vec3(\
scal_mul_vec3(onb.v[0], vec3.e[0]), \
add_vec3(\
scal_mul_vec3(onb.v[1], vec3.e[1]), \
scal_mul_vec3(onb.v[2], vec3.e[2]))));
}
