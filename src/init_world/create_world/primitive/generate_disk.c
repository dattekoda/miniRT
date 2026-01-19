/* ************************************************************************** */
/*                                                                            */
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

static t_disk	construct_disk(t_disk disk_param, t_material *mat_ptr);

/*
@brief if generate_disk failed, mat_ptr->clear()
*/
t_disk	*generate_disk(t_disk disk_param, t_material *mat_ptr)
{
	t_disk	*p;

	p = ft_calloc(1, sizeof(t_material));
	if (!p)
	{
		mat_ptr->clear();
		return (NULL);
	}
	*p = construct_disk(disk_param, mat_ptr);
	return (p);
}

static t_disk	construct_disk(t_disk disk_param, t_material *mat_ptr)
{
	disk_param.hitter.hit = hit_disk;
	disk_param.hitter.clear = clear_primitive;
	disk_param.has_aabb = true;
	disk_param.aabb = construct_disk_aabb(disk_param);
	disk_param.mat_ptr = mat_ptr;
	return (disk_param);
}
