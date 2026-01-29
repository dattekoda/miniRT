/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:52:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/30 01:52:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "solution.h"
#include "rt_utils.h"
#include "vec_utils.h"
#include <math.h>

static t_solution	init_solution_context(const t_point3 *point,
						const t_vec3 *normal, const t_ray *ray);
// static void			assign_hrec(const t_disk *self, const t_ray *ray, 
// 	t_hrec *hrec, const t_solution *solu);

bool	hit_disk(
	const void *s, const t_ray *ray, t_hrec *hrec, t_range *range)
{
	const t_disk	*self;
	t_solution		solu;

	self = s;
	solu = init_solution_context(&self->center, &ray->direct, ray);
	if (fequal(solu.b, 0))
		return (false);
	solu.solution = solu.a / solu.b;
	if (is_inside_range(solu.solution, range) == false)
		return (false);
	hrec->point = at_ray(ray, solu.solution);
	if (length_squared_vec3
		(sub_vec3(hrec->point, self->center)) > pow(self->radius, 2))
		return (false);
	// assign_hrec(self, ray, hrec, range); // ????
	(void)hrec; // 後で消す
	return (true);
}

static t_solution	init_solution_context(
	const t_point3 *center, const t_vec3 *normal, const t_ray *ray)
{
	t_solution	solu;
	t_vec3		center_to_origin;

	ft_bzero(&solu, sizeof(t_solution));
	center_to_origin = sub_vec3(*center, ray->origin);
	solu.a = -dot(center_to_origin, *normal);
	solu.b = dot(ray->direct, *normal);
	return (solu);
}

// static void	assign_hrec(const t_disk *self, const t_ray *ray, 
// 	t_hrec *hrec, const t_solution *solu)
// {
// 	hrec->ray_in = *ray;
// 	hrec->param_t = solu->solution;
// 	hrec->point = at_ray(ray, hrec->param_t);
// 	hrec->normal = normalize(self->normal);
// 	hrec->mat_ptr = self->hitter.mat_ptr;
// 	return ;
// }