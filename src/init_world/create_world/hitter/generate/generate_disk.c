/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_disk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:54:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:05:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "rt_utils.h"
#include "solution.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>
#include <stdlib.h>

static t_disk	construct_disk(t_disk disk_param);
bool			hit_disk(
					const void *s,
					const t_ray *ray, t_hrec *hrec, t_range *range);
static t_aabb	construct_disk_aabb(t_disk disk_param);
t_aabb			construct_aabb(t_point3 min, t_point3 max);
double			calc_normal_max(double d);

/*
@brief if generate_disk failed, mat_ptr->clear()
*/
t_hitter	*generate_disk(t_disk disk_param)
{
	t_disk	*p;

	if (!disk_param.hitter.mat_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_disk));
	if (!p)
	{
		disk_param.hitter.mat_ptr->clear(disk_param.hitter.mat_ptr);
		free(disk_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_disk(disk_param);
	return ((t_hitter *)p);
}

static t_disk	construct_disk(t_disk disk_param)
{
	disk_param.squared_rad = disk_param.radius * disk_param.radius;
	disk_param.hitter.type = DISK;
	disk_param.hitter.hit = hit_disk;
	disk_param.hitter.clear = clear_hitter;
	disk_param.hitter.has_aabb = true;
	disk_param.hitter.aabb = construct_disk_aabb(disk_param);
	return (disk_param);
}

static t_aabb	construct_disk_aabb(t_disk disk)
{
	t_point3	min;
	t_point3	max;
	t_point3	v_max;

	v_max = scal_mul_vec3(
			map_vec3(disk.normal, calc_normal_max), disk.radius);
	min = sub_vec3(
			sub_vec3(disk.center, v_max),
			fill_vec3(PLANE_AABB_THICKNESS));
	max = add_vec3(
			add_vec3(disk.center, v_max),
			fill_vec3(PLANE_AABB_THICKNESS));
	return (construct_aabb(min, max));
}
