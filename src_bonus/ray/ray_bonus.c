/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:19:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"
#include "vec_utils_bonus.h"

static double	calc_inv(double d);

t_ray	construct_ray(t_point3 origin, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direct = dir;
	ray.inv_direct = map_vec3(dir, calc_inv);
	return (ray);
}

t_point3	at_ray(const t_ray *ray, double param_t)
{
	return (add_vec3(ray->origin, scal_mul_vec3(ray->direct, param_t)));
}

static double	calc_inv(double d)
{
	return (1 / d);
}
