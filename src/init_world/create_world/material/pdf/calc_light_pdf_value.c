/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_light_pdf_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:04:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 16:30:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_pdf.h"
#include "sphere.h"
#include "rt_define.h"
#include "vec_utils.h"
#include <math.h>

// static double	calc_light_list_pdf_value(
// 					const t_list *light_list,
// 					const t_point3 *point,
// 					const t_vec3 *direct);
static double	calc_light_sphere_pdf_value(
					const t_sphere *sphere,
					const t_point3 *point,
					const t_vec3 *direct);
static double	calc_solid_angle(
					const t_sphere *sphere, const t_point3 *point);

#include "rt_debug.h"
#include <stdlib.h>
#include <stdio.h>
double	calc_light_pdf_value(const void *s, const t_vec3 *direct)
{
	const t_light_pdf	*self = s;
	const t_list		*light_list = self->light_list;
	double				pdf_sum;

	pdf_sum = 0;
	// fprintf(stderr, "inside calc_light_pdf_value()\n");
	// print_vec3(*direct);
	while (light_list)
	{
		// print_hitter(light_list->content);
		pdf_sum += calc_light_sphere_pdf_value(light_list->content, &self->point, direct);
		light_list = light_list->next;
	}
	// fprintf(stderr, "pdf_sum:%f\n", pdf_sum);
	// exit(1);
	return (pdf_sum);
}

static double	calc_light_sphere_pdf_value(
					const t_sphere *sphere,
					const t_point3 *point,
					const t_vec3 *direct)
{
	const t_ray		ray = construct_ray(*point, *direct);
	t_hrec			hrec;
	t_range			range;

	range = construct_vec2(HIT_T_MIN, INFINITY); 
	if (!sphere->hitter.hit(sphere, &ray, &hrec, &range))
		return (0);
	return (1 / calc_solid_angle(sphere, point));
}

static double	calc_solid_angle(
					const t_sphere *sphere, const t_point3 *point)
{
	const double	squared_distance
		= length_squared_vec3(sub_vec3(sphere->center, *point));
	const double	cos_theta_max
		= sqrt(1 - pow(sphere->radius, 2) / squared_distance);

	return (2 * M_PI * (1 - cos_theta_max));
}
