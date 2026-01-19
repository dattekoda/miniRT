/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:19:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/19 22:21:40 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec_utils.h"

t_ray	construct_ray(t_point3 origin, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direct = dir;
	return (ray);
}

t_point3	at_ray(t_ray ray, double param_t)
{
	return (add_vec3(ray.origin, scal_mul_vec3(ray.direct, param_t)));
}
