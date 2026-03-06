/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_light_pdf_direction.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:03:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 19:20:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "axis.h"
#include "light_pdf.h"
#include "vec_utils.h"
#include "sphere.h"
#include "rt_utils.h"
#include "rt_define.h"
#include <math.h>

static t_vec3	generate_target_sphere_direction(
					const t_sphere *sphere, const t_point3 *point);
static t_vec3	generate_random_direction_to_sphere(
					double radius, double squared_distance);

t_vec3	generate_light_pdf_direction(const void *s)
{
	const t_light_pdf	*self = s;
	const t_list		*light_list = self->light_list;
	const size_t		count = (size_t)ft_lstsize((t_list *)light_list);
	size_t				target;
	size_t				i;

	if (count == 0)
		return (constant_vec3(0));
	target = (size_t)random_double(0, count - 0.001);
	i = 0;
	while (light_list)
	{
		if (i == target)
			return (generate_target_sphere_direction(
					light_list->content, &self->point));
		light_list = light_list->next;
		i++;
	}
	return (constant_vec3(0));
}

static t_vec3	generate_target_sphere_direction(
					const t_sphere *sphere, const t_point3 *point)
{
	const t_vec3	direct = sub_vec3(sphere->center, *point);
	const t_onb		onb = construct_onb(direct);
	const double	squared_distance = length_squared_vec3(direct);

	return (local_onb(onb,
			generate_random_direction_to_sphere(
				sphere->radius,
				squared_distance)));
}

static t_vec3	generate_random_direction_to_sphere(
					double radius,
					double squared_distance)
{
	t_vec3			vec;
	const double	u1 = random_01();
	const double	u2 = random_01();
	const double	phi = 2 * M_PI * u1;
	const double	cos_theta_max
		= sqrt(1 - radius * radius / squared_distance);

	vec.e[A_Z] = 1 + u2 * (cos_theta_max - 1);
	vec.e[A_X] = cos(phi) * sqrt(1 - vec.e[A_Z] * vec.e[A_Z]);
	vec.e[A_Y] = sin(phi) * sqrt(1 - vec.e[A_Z] * vec.e[A_Z]);
	return (vec);
}
