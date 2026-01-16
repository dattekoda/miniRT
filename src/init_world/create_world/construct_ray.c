/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:23:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 16:24:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	construct_ray(t_point3 ori, t_vec3 dir)
{
	t_ray	ray;

	ray.ori = ori;
	ray.dir = dir;
	return (ray);
}
