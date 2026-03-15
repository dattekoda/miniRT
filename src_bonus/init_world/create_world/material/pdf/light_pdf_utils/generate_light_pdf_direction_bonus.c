/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_light_pdf_direction_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:03:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 22:24:29 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "axis_bonus.h"
#include "light_pdf_bonus.h"
#include "vec_utils_bonus.h"
#include "sphere_bonus.h"
#include "rt_utils_bonus.h"
#include "rt_define_bonus.h"
#include <math.h>

static t_vec3	generate_target_sphere_direction(
					const t_sphere *sphere,
					const t_point3 *point,
					uint64_t *seed);
static t_vec3	generate_random_direction_to_sphere(
					double radius,
					double squared_distance,
					uint64_t *seed);

t_vec3	generate_light_pdf_direction(const void *s, uint64_t *seed)
{
	const t_light_pdf	*self = s;
	const t_list		*light_list = self->light_list;
	const size_t		count = (size_t)ft_lstsize((t_list *)light_list);
	size_t				target;
	size_t				i;

	if (count == 0)
		return (fill_vec3(0));
	target = (size_t)random_double(0, count - 0.001, seed);
	i = 0;
	while (light_list)
	{
		if (i == target)
			return (generate_target_sphere_direction(
					light_list->content, &self->point, seed));
		light_list = light_list->next;
		i++;
	}
	return (fill_vec3(0));
}

static t_vec3	generate_target_sphere_direction(
					const t_sphere *sphere,
					const t_point3 *point,
					uint64_t *seed)
{
	const t_vec3	direct = sub_vec3(sphere->center, *point);
	const t_onb		onb = construct_onb(direct);
	const double	squared_distance = length_squared_vec3(direct);

	return (local_onb(onb,
			generate_random_direction_to_sphere(
				sphere->radius,
				squared_distance,
				seed)));
}

static t_vec3	generate_random_direction_to_sphere(
					double radius,
					double squared_distance,
					uint64_t *seed)
{
	t_vec3			vec;
	const double	u1 = random_01(seed);
	const double	u2 = random_01(seed);
	const double	phi = 2 * M_PI * u1;
	const double	cos_theta_max
		= sqrt(1 - radius * radius / squared_distance);

	vec.e[A_Z] = 1 + u2 * (cos_theta_max - 1);
	vec.e[A_X] = cos(phi) * sqrt(1 - vec.e[A_Z] * vec.e[A_Z]);
	vec.e[A_Y] = sin(phi) * sqrt(1 - vec.e[A_Z] * vec.e[A_Z]);
	return (vec);
}
