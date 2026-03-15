/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:21:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils_bonus.h"
#include <math.h>

t_vec3	refract(
			const t_vec3 unit_ray_in_direct,
			const t_vec3 normal,
			double refract_ratio)
{
	const double	cos_theta = dot(negative_vec3(unit_ray_in_direct), normal);
	const t_vec3	next_ray_direct_parallel
		= scal_mul_vec3(
			add_vec3(
				unit_ray_in_direct,
				scal_mul_vec3(normal, cos_theta)),
			refract_ratio);
	const t_vec3	next_ray_direct_perp
		= scal_mul_vec3(
			normal,
			-sqrt(1 - length_squared_vec3(next_ray_direct_parallel)));

	return (add_vec3(next_ray_direct_parallel, next_ray_direct_perp));
}
