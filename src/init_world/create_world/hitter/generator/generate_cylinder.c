/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:07:16 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/30 06:25:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include <math.h>

static t_cylinder	construct_cylinder(t_cylinder shape_param);
static t_aabb		construct_cylinder_aabb(t_cylinder cylinder);
t_aabb				construct_aabb(t_point3 min, t_point3 max);
double				calc_normal_max(double d);
static t_vec3		map2_vec3(t_vec3 a, t_vec3 b, double(*f)(double, double));

t_hitter	*generate_cylinder(t_cylinder cylinder_param)
{
	t_cylinder	*p;

	p = ft_calloc(1, sizeof(t_cylinder));
	if (!p)
	{
		cylinder_param.hitter.mat_ptr->clear(cylinder_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_cylinder(cylinder_param);
	return ((t_hitter *)p);
}

static t_cylinder	construct_cylinder(t_cylinder shape_param)
{
	t_cylinder	cylinder;

	ft_memmove(&cylinder, &shape_param, sizeof(t_cylinder));
	// cylinder.hitter.hit = hit_cylinder;
	cylinder.hitter.clear = clear_hitter;
	cylinder.hitter.has_aabb = true;
	cylinder.hitter.aabb = construct_cylinder_aabb(cylinder);
	return (cylinder);
}

static t_aabb	construct_cylinder_aabb(t_cylinder cylinder)
{
	t_point3	v_max;
	t_point3	top_center;
	t_vec3		min;
	t_vec3		max;

	v_max = scal_mul_vec3(map_vec3(cylinder.direct, calc_normal_max),
				cylinder.radius);
	top_center = add_vec3(cylinder.center,
				scal_mul_vec3(cylinder.direct, cylinder.height));
	min = sub_vec3(map2_vec3(cylinder.center, top_center, fmin), v_max);
	max = add_vec3(map2_vec3(cylinder.center, top_center, fmax), v_max);
	return (construct_aabb(min, max));
}

static t_vec3	map2_vec3(t_vec3 a, t_vec3 b, double(*f)(double, double))
{
	t_vec3	output;
	size_t	i;

	i = 0;
	while (i < 3)
	{
		output.e[i] = f(a.e[i], b.e[i]);
		i++;
	}
	return (output);
}
