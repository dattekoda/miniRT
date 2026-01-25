/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_light_pdf_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:04:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:24:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_pdf.h"
#include "sphere.h"
#include "rt_define.h"
#include "vec_utils.h"
#include <math.h>

static double	calc_light_list_pdf_value
	(const t_list *light_list, const t_point3 *point, const t_vec3 *direct);
static double	calc_sphere_pdf_value
	(const t_sphere *sphere, const t_point3 *point, const t_vec3 *direct);
static double	calc_solid_angle
	(const t_sphere *sphere, const t_point3 *point);

double	calc_light_pdf_value(const void *s, const t_vec3 *direct)
{
	const t_light_pdf	*self;

	self = s;
	return (calc_sphere_pdf_value(self->light_list, &self->point, direct));
}

static double	calc_light_list_pdf_value
	(const t_list *light_list, const t_point3 *point, const t_vec3 *direct)
{
	double		pdf_sum;

	pdf_sum = 0;
	while (light_list)
	{
		pdf_sum += calc_sphere_pdf_value(light_list->content, point, direct);
		light_list = light_list->next;
	}
	return (pdf_sum);
}

static double	calc_sphere_pdf_value
	(const t_sphere *sphere, const t_point3 *point, const t_vec3 *direct)
{
	t_hrec	hrec;
	t_range	range;
	t_ray	ray;

	range = construct_vec2(HIT_T_MIN, INFINITY);
	ray = construct_ray(*point, *direct);
	if (!sphere->hitter.hit(sphere, &ray, &hrec, &range))
		return (0);
	return (1 / calc_solid_angle(sphere, point));
}

static double	calc_solid_angle
	(const t_sphere *sphere, const t_point3 *point)
{
	double	cos_theta_max;
	double	distance;

	distance = length_squared_vec3(sub_vec3(sphere->center, *point));
	cos_theta_max = sqrt(1 - pow(sphere->radius, 2)) / distance;
	return (2 * M_PI * (1 - cos_theta_max));
}
