/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:57:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 15:30:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "solution.h"
#include "vec_utils.h"
#include "rt_define.h"

static t_solution	init_solution_context
	(const t_sphere *self, const t_ray *ray);
static void			assign_sphere_hrec
	(const t_sphere *self, const t_ray *ray, t_hrec *hrec, double solution);
static t_vec2		construct_sphere_uv(const t_vec3 *unit_normal);

bool	hit_sphere
	(const void *s, const t_ray *ray, t_hrec *hrec, const t_range *range)
{
	t_sphere	*self;
	t_solution	solu;

	self = s;
	solu = init_solution_context(self, ray);
	if (solu.discriminant < 0)
		return (false);
	solu.root_discriminant = sqrt(solu.discriminant);
	solu.solution = calc_minus_solution(&solu);
	if (is_inside_range(solu.solution, range) == true)
	{
		assign_sphere_hrec(self, ray, hrec, solu.solution);
		return (true);
	}
	solu.solution = calc_plus_solution(&solu);
	if (is_inside_range(solu.solution, range) == true)
	{
		assign_sphere_hrec(self, ray, hrec, solu.solution);
		return (true);
	}
	return (false);
}

static t_solution	init_solution_context
	(const t_sphere *self, const t_ray *ray)
{
	t_solution	solu;

	ft_bzero(&solu, sizeof(t_solution));
	solu.center_to_origin = sub_vec3(ray->origin, self->center);
	solu.a = length_squared_vec3(ray->direct);
	solu.b = dot(solu.center_to_origin, ray->direct);
	solu.c = length_squared_vec3(solu.center_to_origin) 
		- pow(self->radius, 2);
	solu.discriminant = calc_discriminant(&solu);
	return (solu);
}

static void		assign_sphere_hrec
	(const t_sphere *self, const t_ray *ray, t_hrec *hrec, double solution)
{
	hrec->ray_in = *ray;
	hrec->param_t = solution;
	hrec->point = at_ray(ray, hrec->param_t);
	hrec->normal = scal_div_vec3
		(sub_vec3(hrec->point, self->center), self->radius);
	hrec->mat_ptr = self->hitter.mat_ptr;
	hrec->map = construct_sphere_uv(&hrec->normal);
	return ;
}

static t_vec2	construct_sphere_uv(const t_vec3 *unit_normal)
{
	t_vec2	map;
	double	phi;
	double	theta;

	phi = atan2(unit_normal->e[2], unit_normal->e[0]);
	theta = asin(unit_normal->e[1]);
	map.e[0] = 1.0 - (phi + M_PI) / (2 * M_PI);
	map.e[1] = (theta + M_PI / 2) / M_PI;
	return (map);
}