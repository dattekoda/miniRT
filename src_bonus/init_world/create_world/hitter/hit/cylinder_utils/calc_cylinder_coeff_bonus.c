/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cylinder_coeff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:03:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils_bonus.h"
#include <math.h>

t_vec3	calc_cylinder_coeff(
	const t_vec3 *ray_direct,
	const t_vec3 *center_to_ray_origin,
	const t_vec3 *cylinder_dir,
	double radius)
{
	const double	len_sq_ray_dir
		= length_squared_vec3(*ray_direct);
	const double	len_sq_c_to_ro
		= length_squared_vec3(*center_to_ray_origin);
	const double	dot_ray_dir__cy_dir
		= dot(*ray_direct, *cylinder_dir);
	const double	dot_cy_dir__c_to_ro
		= dot(*cylinder_dir, *center_to_ray_origin);
	const double	dot_c_to_ro__ray_dir
		= dot(*center_to_ray_origin, *ray_direct);

	return (construct_vec3(
			len_sq_ray_dir - dot_ray_dir__cy_dir * dot_ray_dir__cy_dir,
			dot_c_to_ro__ray_dir - dot_ray_dir__cy_dir * dot_cy_dir__c_to_ro,
			len_sq_c_to_ro
			- dot_cy_dir__c_to_ro * dot_cy_dir__c_to_ro - radius * radius));
}
