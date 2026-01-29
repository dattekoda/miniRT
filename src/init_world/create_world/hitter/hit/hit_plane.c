/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:37:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/30 00:49:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include "ray.h"
#include "plane.h"
#include "init_world_define.h"
#include "vec_utils.h"
#include <float.h>
#include <math.h>

static t_solution	init_soluion(const t_plane *self, const t_ray *ray);
static void			assign_plane_hrec(
						const t_plane *self,
						const t_ray *ray, t_hrec *hrec, double solution);
static t_point2		construct_plane_uv(
						const t_vec3 *normal,
						const t_vec3 *hit_point,
						const t_vec3 *plane_point);

bool	hit_plane(
	const void *s, const t_ray *ray, t_hrec *hrec, t_range *range)
{
	const t_plane	*self;
	t_solution		solu;

	self = s;
	solu = init_soluion(self, ray);
	if (fabs(solu.b) < FLT_EPSILON)
		return (false);
	solu.solution = solu.a / solu.b;
	if (is_inside_range(solu.solution, range))
	{
		assign_plane_hrec(self, ray, hrec, solu.solution);
		return (true);
	}
	return (false);
}

static t_solution	init_soluion(const t_plane *self, const t_ray *ray)
{
	t_solution	solu;
	t_vec3		point_to_ray_origin;

	point_to_ray_origin = sub_vec3(ray->origin, self->point);
	solu.a = dot(point_to_ray_origin, self->normal);
	solu.b = dot(ray->direct, self->normal);
	return (solu);
}

static void	assign_plane_hrec(
				const t_plane *self,
				const t_ray *ray, t_hrec *hrec, double solution)
{
	hrec->ray_in = *ray;
	hrec->param_t = solution;
	hrec->point = at_ray(ray, hrec->param_t);
	hrec->normal = self->normal;
	hrec->mat_ptr = self->hitter.mat_ptr;
	hrec->map = construct_plane_uv(&hrec->normal, &hrec->point, &self->point);
}

static t_point2	construct_plane_uv(
					const t_vec3 *normal,
					const t_vec3 *hit_point,
					const t_vec3 *plane_point)
{
	t_point2	map;
	t_vec3		offset;
	t_onb		onb;

	onb = construct_onb(*normal);
	offset = sub_vec3(*hit_point, *plane_point);
	map.e[0] = dot(offset, onb.v[0]) / (int)UNIT_EDGE;
	map.e[1] = dot(offset, onb.v[1]) / (int)UNIT_EDGE;
	map.e[0] = map.e[0] - floor(map.e[0]);
	map.e[1] = map.e[1] - floor(map.e[1]);
	return (map);
}
