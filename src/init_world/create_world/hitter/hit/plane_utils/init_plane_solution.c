/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_solution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:01:05 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/04 15:44:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include "vec_utils.h"
#include "ray.h"

void	init_plane_solution(
			t_solution *solu,
			const t_vec3 *normal,
			const t_point3 *point,
			const t_ray *ray)
{
	const t_vec3	point_to_ray_origin = sub_vec3(*point, ray->origin);

	solu->coeff.e[0] = dot(point_to_ray_origin, *normal);
	solu->coeff.e[1] = dot(ray->direct, *normal);
	return ;
}
