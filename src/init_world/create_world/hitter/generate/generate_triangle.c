/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:54:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 19:37:16 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "axis.h"
#include "triangle.h"
#include "rt_utils.h"
#include "solution.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>
#include <stdlib.h>

static t_triangle	construct_triangle(t_triangle triangle_param);
bool				hit_triangle(
						const void *s,
						const t_ray *ray, t_hrec *hrec, t_range *range);
t_aabb				construct_aabb(t_point3 min, t_point3 max);
double				calc_normal_max(double d);
static t_aabb		construct_triangle_aabb(t_triangle triangle_param);
static double		get_min_bound_for_axis(t_point3 vtx[3], int axis);
static double		get_max_bound_for_axis(t_point3 vtx[3], int axis);

/*
@brief if generate_triangle failed, mat_ptr->clear()
*/
t_hitter	*generate_triangle(t_triangle triangle_param)
{
	t_triangle	*p;

	if (!triangle_param.hitter.mat_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_triangle));
	if (!p)
	{
		triangle_param.hitter.mat_ptr->clear(triangle_param.hitter.mat_ptr);
		free(triangle_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_triangle(triangle_param);
	return ((t_hitter *)p);
}

static t_triangle	construct_triangle(t_triangle triangle_param)
{
	triangle_param.hitter.type = TRIANGLE;
	triangle_param.hitter.hit = hit_triangle;
	triangle_param.hitter.clear = clear_hitter;
	triangle_param.hitter.has_aabb = true;
	triangle_param.hitter.aabb = construct_triangle_aabb(triangle_param);
	triangle_param.edge[0]
		= sub_vec3(triangle_param.vertex[1], triangle_param.vertex[0]);
	triangle_param.edge[1]
		= sub_vec3(triangle_param.vertex[2], triangle_param.vertex[0]);
	triangle_param.normal = normalize_vec3(
			cross(triangle_param.edge[0], triangle_param.edge[1]));
	return (triangle_param);
}

static t_aabb	construct_triangle_aabb(t_triangle triangle)
{
	t_point3	min;
	t_point3	max;

	min = construct_vec3(
			get_min_bound_for_axis(triangle.vertex, A_X),
			get_min_bound_for_axis(triangle.vertex, A_Y),
			get_min_bound_for_axis(triangle.vertex, A_Z));
	max = construct_vec3(
			get_max_bound_for_axis(triangle.vertex, A_X),
			get_max_bound_for_axis(triangle.vertex, A_Y),
			get_max_bound_for_axis(triangle.vertex, A_Z));
	return (construct_aabb(min, max));
}

static double	get_min_bound_for_axis(t_point3 vtx[3], int axis)
{
	return (fmin(fmin(
				vtx[0].e[axis],
				vtx[1].e[axis]),
			vtx[2].e[axis]) - PLANE_AABB_THICKNESS);
}

static double	get_max_bound_for_axis(t_point3 vtx[3], int axis)
{
	return (fmax(fmax(
				vtx[0].e[axis],
				vtx[1].e[axis]),
			vtx[2].e[axis]) + PLANE_AABB_THICKNESS);
}
