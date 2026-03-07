/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:37:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/07 14:47:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include "ray.h"
#include "plane.h"
#include "init_world_define.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include <float.h>
#include <math.h>

void		init_plane_solution(
				t_solution *solu,
				const t_vec3 *normal,
				const t_point3 *point,
				const t_ray *ray);
t_point2	construct_plane_uv(
				const t_vec3 *normal,
				const t_vec3 *hit_point,
				const t_vec3 *plane_point);
static void	assign_plane_hrec(
				const t_plane *self,
				const t_ray *ray, t_hrec *hrec, double solution);

bool	hit_plane(
	const void *s, const t_ray *ray, t_hrec *hrec, t_range *range)
{
	const t_plane	*self;
	t_solution		solu;

	self = s;
	init_plane_solution(&solu, &self->normal, &self->point, ray);
	if (fequal(solu.coeff.e[1], 0))
		return (false);
	solu.solution = solu.coeff.e[0] / solu.coeff.e[1];
	if (!is_inside_range(solu.solution, range))
		return (false);
	assign_plane_hrec(self, ray, hrec, solu.solution);
	range->e[1] = hrec->param_t;
	return (true);
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
	return ;
}
