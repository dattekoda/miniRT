/*                                                        :::      ::::::::   */
/*   generate_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:23:41 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/17 23:45:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "rt_utils.h"
#include "solution.h"
#include "vec_utils.h"
#include "hitter_utils.h"

static t_disk	construct_disk(t_disk disk_param);
bool	hit_disk
	(const void *s, const t_ray *ray, t_hrec *hrec, const t_range *range);

/*
@brief if generate_disk failed, mat_ptr->clear()
*/
t_disk	*generate_disk(t_disk disk_param)
{
	t_disk	*p;

	if (!disk_param.hitter.mat_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_material));
	if (!p)
	{
		disk_param.hitter.mat_ptr->clear(disk_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_disk(disk_param);
	return (p);
}

static t_disk	construct_disk(t_disk disk_param)
{
	disk_param.hitter.hit = hit_disk;
	disk_param.hitter.clear = clear_hitter;
	disk_param.hitter.has_aabb = true;
	disk_param.hitter.aabb = construct_disk_aabb(disk_param);
	return (disk_param);
}

static t_aabb	construct_disk_aabb(t_disk disk_param)
{
	t_point3	min;
	t_point3	max;
	t_point3	v_max;
	t_point3	constant;

	v_max = map_vec3(disk_param.normal, calc_normal_max);
	constant = constant_vec3(disk_param.radius);
	v_max = mul_vec3(constant, v_max);
	min = sub_vec3(disk_param.center, v_max);
	max = add_vec3(disk_param.center, v_max);
	return (construct_aabb(min, max));
}

static float	calc_normal_max(float d)
{
	return (sqrt(1 - pow(d, 2)));
}
