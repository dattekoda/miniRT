/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:55:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 17:03:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_utils.h"
#include "solution.h"
#include "sphere.h"
#include "solid_texture.h" // textutre table.hか何かに変更よてい
#include "lambertian.h" // 同上。
#include "init_world_utils.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "rt_define.h"
#include "ray.h"
#include "libft.h"
#include <math.h>

static t_sphere	construct_sphere(t_sphere shape_param);
static bool		hit_sphere(void *self, t_ray ray, t_hrec *hrec, t_range range);
static void		assign_sphere_hrec
	(const t_sphere *self, t_hrec *hrec, const t_ray ray, double solution);
static t_vec2	construct_sphere_uv(t_vec3 unit_normal);

/*
@brief responsible for free(mat_ptr)
*/
t_hitter	*generate_sphere(t_sphere shape_param)
{
	t_sphere	*p;

	p = ft_calloc(1, sizeof(t_sphere));
	if (!p)
	{
		shape_param.hitter.mat_ptr->clear(shape_param.hitter.mat_ptr);
		return (NULL);
	}
	*p = construct_sphere(shape_param);
	return ((t_hitter *)p);
}

static t_sphere	construct_sphere(t_sphere shape_param)
{
	t_sphere	sphere;

	ft_memmove(&sphere, &shape_param, sizeof(t_sphere));
	sphere.hitter.hit = hit_sphere;
	sphere.hitter.clear = clear_primitive;
	sphere.hitter.has_aabb = true;
	sphere.hitter.aabb = construct_aabb(
		sub_vec3(sphere.center, constant_vec3(sphere.radius)), 
			add_vec3(sphere.center, constant_vec3(sphere.radius)));
	return (sphere);
}

static bool	hit_sphere(void *s, t_ray ray, t_hrec *hrec, t_range range)
{
	t_sphere	*self;
	t_vec3		c_to_o; // center to origin
	t_solution	solu;

	self = s;
	c_to_o = sub_vec3(ray.origin, self->center);
	solu.abc.e[0] = length_squared_vec3(ray.direct);
	solu.abc.e[1] = dot(c_to_o, ray.direct);
	solu.abc.e[2] = length_squared_vec3(c_to_o) - pow(self->radius, 2);
	solu.discriminant = calc_discriminant(solu.abc);
	if (solu.discriminant < 0)
		return (false);
	solu.root_discriminant = sqrt(solu.discriminant);
	solu.solution = calc_minus_solution(solu);
	if (is_inside_range(solu.solution, range) == true)
		return (assign_sphere_hrec(self, hrec, ray, solu.solution), true);
	solu.solution = calc_plus_solution(solu);
	if (is_inside_range(solu.solution, range) == true)
		return (assign_sphere_hrec(self, hrec, ray, solu.solution), true);
	return (false);
}

static void		assign_sphere_hrec
	(const t_sphere *self, t_hrec *hrec, const t_ray ray, double solution)
{
	hrec->ray_in = ray;
	hrec->param_t = solution;
	hrec->point = at_ray(ray, hrec->param_t);
	hrec->normal = scal_div_vec3
		(sub_vec3(hrec->point, self->center), self->radius);
	hrec->mat_ptr = self->hitter.mat_ptr;
	hrec->map = construct_sphere_uv(hrec->normal);
	return ;
}

static t_vec2	construct_sphere_uv(t_vec3 unit_normal)
{
	t_vec2	map;
	double	phi;
	double	theta;

	phi = atan2(unit_normal.e[2], unit_normal.e[0]);
	theta = asin(unit_normal.e[1]);
	map.e[0] = 1.0 - (phi + M_PI) / (2 * M_PI);
	map.e[1] = (theta + M_PI / 2) / M_PI;
	return (map);
}
