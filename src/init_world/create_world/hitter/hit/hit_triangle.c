/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:27:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/07 20:44:39 by ikawamuk         ###   ########.fr       */
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
static bool	is_inside_of_triangle(t_triangle triangle, t_point3 point);

bool	hit_triangle(
			const void *s, const t_ray *ray, t_hrec *hrec, t_range *range)
{
	const t_triangle	*self;
	t_solution		solu;

	self = s;
	init_plane_solution(&solu, &self->normal, &self->vertex[0], ray);
	if (fequal(solu.coeff.e[1], 0))
		return (false);
	solu.solution = solu.coeff.e[0] / solu.coeff.e[1];
	if (!is_inside_range(solu.solution, range))
		return (false);
	solu.point = at_ray(ray, solu.solution);
	if (!is_inside_of_triangle(*self, solu.point))
		return (false);
	assign_triangle_hrec(self, ray, hrec, &solu);
	return (true);
}

static bool	is_inside_of_triangle(t_triangle triangle, t_point3 point)
{
	const t_point3	ap = sub_vec3(point, triangle.vertex[0]);
	const t_point3	bp = sub_vec3(point, triangle.vertex[1]);
	const t_point3	cp = sub_vec3(point, triangle.vertex[2]);

	return (dot(triangle.normal, cross(triangle.side[0], ap)) < 0
		|| dot(triangle.normal, cross(triangle.side[0], bp)) < 0
		|| dot(triangle.normal, cross(triangle.side[0], cp)) < 0
	);
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
	hrec->map = construct_plane_uv(&self->normal,
					&hrec->point, &self->vertex[0]);
	return ;
}
