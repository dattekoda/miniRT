/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:55:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 21:38:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "solid_texture.h" // textutre table.hか何かに変更よてい
#include "lambertian.h" // 同上。
#include "init_world_utils.h"
#include "libft.h"



void	clear_premitive(void *self);



t_sphere	*gen_sphere(t_sphere shape_param, t_material *mat_ptr)
{
	t_sphere	*p;

	if (!mat_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_sphere));
	if (!p)
		return (mat_ptr->clear(mat_ptr), NULL);
	*p = construct_sphere(param, mat_ptr);
	return (p);
}

static t_sphere	construct_sphere(t_sphere_param param, t_material *mat_ptr)
{
	t_sphere	sphere;

	sphere.center = param->center;
	sphere.radius = param->radius;
	sphere.hitter.hit = hit_sphere;
	sphere.hitter.clear = clear_premitive;
	sphere.hitter.has_aabb = 1;
	sphere.hitter.aabb = construct_sphere_aabb();
	sphere.hitter.mat_ptr = mat_ptr;
	return (sphere);
}
