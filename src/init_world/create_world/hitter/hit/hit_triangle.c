/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:27:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/20 19:10:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"
#include "plane.h"
#include "solution.h"
#include "rt_utils.h"
#include "vec_utils.h"
#include <math.h>

void				init_plane_solution(
						t_solution *solu,
						const t_vec3 *normal,
						const t_point3 *point,
						const t_ray *ray);
t_point2			construct_plane_uv(
						const t_vec3 *normal,
						const t_vec3 *hit_point,
						const t_vec3 *plane_point);
static void			assign_triangle_hrec(
						const t_triangle *self,
						const t_ray *ray,
						t_hrec *hrec,
						const t_solution *solu);
static bool			is_inside_triangle(
						const t_triangle *tri,
						const t_point3 *point);
static bool			is_point_same_side(
						const t_triangle *tri,
						const t_vec3 vtx_to_p[3]);

// TODO: still unsure but maybe need to fix range->e[1]'s update
bool	hit_triangle(
			const void *s,
			const t_ray *ray,
			t_hrec *hrec,
			t_range *range)
{
	const t_triangle	*self;
	t_solution			solu;

	self = s;
	init_plane_solution(&solu, &self->normal, &self->vertex[0], ray);
	if (fequal(solu.coeff.e[1], 0))
		return (false);
	solu.solution = solu.coeff.e[0] / solu.coeff.e[1];
	if (!is_inside_range(solu.solution, range))
		return (false);
	solu.point = at_ray(ray, solu.solution);
	if (!is_inside_triangle(self, &solu.point))
		return (false);
	assign_triangle_hrec(self, ray, hrec, &solu);
	// range->e[1] = hrec->param_t;
	return (true);
}

static bool	is_inside_triangle(
						const t_triangle *tri,
						const t_point3 *point)
{
	t_vec3	vertex_to_point[3];

	vertex_to_point[0] = sub_vec3(*point, tri->vertex[0]);
	vertex_to_point[1] = sub_vec3(*point, tri->vertex[1]);
	vertex_to_point[2] = sub_vec3(*point, tri->vertex[2]);
	return (is_point_same_side(tri, vertex_to_point));
}

static bool	is_point_same_side(
				const t_triangle *tri,
				const t_vec3 vtx_to_p[3])
{
	bool	is_negative[3];

	is_negative[0] = dot(tri->normal, cross(tri->side[0], vtx_to_p[0])) < 0;
	is_negative[1] = dot(tri->normal, cross(tri->side[1], vtx_to_p[1])) < 0;
	is_negative[2] = dot(tri->normal, cross(tri->side[2], vtx_to_p[2])) < 0;
	return ((is_negative[0] && is_negative[1] && is_negative[2])
		|| (!is_negative[0] && !is_negative[1] && !is_negative[2]));
}

static void	assign_triangle_hrec(
				const t_triangle *self,
				const t_ray *ray,
				t_hrec *hrec,
				const t_solution *solu)
{
	hrec->ray_in = *ray;
	hrec->param_t = solu->solution;
	hrec->point = solu->point;
	hrec->normal = self->normal;
	hrec->mat_ptr = self->hitter.mat_ptr;
	hrec->map = construct_plane_uv(
			&self->normal,
			&hrec->point,
			&self->vertex[0]);
	return ;
}
