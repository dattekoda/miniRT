/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_sphere_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:55:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_utils_bonus.h"
#include "solution_bonus.h"
#include "sphere_bonus.h"
#include "solid_texture_bonus.h"
#include "lambertian_bonus.h"
#include "init_world_utils_bonus.h"
#include "vec_utils_bonus.h"
#include "rt_utils_bonus.h"
#include "rt_define_bonus.h"
#include "ray_bonus.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

bool			hit_sphere(
					const void *s,
					const t_ray *ray, t_hrec *hrec, t_range *range);
static t_sphere	construct_sphere(t_sphere shape_param);
static t_aabb	construct_sphere_aabb(const t_sphere *sphere);

/*
@brief responsible for free(mat_ptr)
*/
t_hitter	*generate_sphere(t_sphere shape_param)
{
	t_sphere	*p;

	if (!shape_param.hitter.mat_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_sphere));
	if (!p)
	{
		shape_param.hitter.mat_ptr->clear(shape_param.hitter.mat_ptr);
		free(shape_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_sphere(shape_param);
	return ((t_hitter *)p);
}

static t_sphere	construct_sphere(t_sphere shape_param)
{
	t_sphere	sphere;

	ft_memmove(&sphere, &shape_param, sizeof(t_sphere));
	sphere.hitter.type = SPHERE;
	sphere.hitter.hit = hit_sphere;
	sphere.hitter.clear = clear_hitter;
	sphere.hitter.has_aabb = true;
	sphere.hitter.aabb = construct_sphere_aabb(&sphere);
	return (sphere);
}

static t_aabb	construct_sphere_aabb(const t_sphere *sphere)
{
	t_point3	min;
	t_point3	max;

	min = sub_vec3(sphere->center, constant_vec3(sphere->radius));
	max = add_vec3(sphere->center, constant_vec3(sphere->radius));
	return (construct_aabb(min, max));
}
