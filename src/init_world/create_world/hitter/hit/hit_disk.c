/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:52:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 18:43:17 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "plane.h"
#include "solution.h"
#include "rt_utils.h"
#include "vec_utils.h"
#include <math.h>

// static t_solution	init_solution_context(const t_point3 *point,
// 						const t_vec3 *normal, const t_ray *ray);
void				init_plane_solution(
						t_solution *solu,
						const t_vec3 *normal,
						const t_point3 *point,
						const t_ray *ray);
t_point2			construct_plane_uv(
						const t_vec3 *normal,
						const t_vec3 *hit_point,
						const t_vec3 *plane_point);
static void			assign_disk_hrec(
						const t_disk *self,
						const t_ray *ray,
						t_hrec *hrec,
						const t_solution *solu);

bool	hit_disk(
			const void *s, const t_ray *ray, t_hrec *hrec, t_range *range)
{
	const t_disk	*self;
	t_solution		solu;

	self = s;
	init_plane_solution(&solu, &self->normal, &self->center, ray);
	if (fequal(solu.coeff.e[1], 0))
		return (false);
	solu.solution = solu.coeff.e[0] / solu.coeff.e[1];
	if (!is_inside_range(solu.solution, range))
		return (false);
	solu.point = at_ray(ray, solu.solution);
	if (length_squared_vec3(sub_vec3(solu.point, self->center))
		> pow(self->radius, 2))
		return (false);
	assign_disk_hrec(self, ray, hrec, &solu);
	range->e[1] = hrec->param_t;
	return (true);
}

static void	assign_disk_hrec(
				const t_disk *self,
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
					&hrec->point, &self->center);
	return ;
}
