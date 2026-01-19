/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:23:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 16:35:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	construct_ray(t_point3 ori, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = ori;
	ray.direct = dir;
	return (ray);
}
