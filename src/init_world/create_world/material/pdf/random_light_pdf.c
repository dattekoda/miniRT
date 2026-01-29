/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_light_pdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:03:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 19:37:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_pdf.h"
#include "vec_utils.h"
#include "sphere.h"
#include "rt_utils.h"
#include "rt_define.h"
#include <math.h>

static size_t	count_list_size(const t_list *lst);
static t_vec3	random_light_list_pdf(
					const t_list *light_list, const t_point3 *point);
static t_vec3	random_sphere(const t_sphere *sphere, const t_point3 *point);
static t_vec3	random_to_sphere(double radius, double squared_distance);

t_vec3	random_light_pdf(const void *s)
{
	const t_light_pdf	*self;

	self = s;
	return (random_light_list_pdf(self->light_list, &self->point));
}

static t_vec3	random_light_list_pdf(
					const t_list *light_list, const t_point3 *point)
{
	size_t	count;
	size_t	target;
	size_t	i;

	count = count_list_size(light_list);
	if (count == 0)
		return (constant_vec3(0));
	target = (size_t)random_int(0, (int)count - 1);
	i = 0;
	while (light_list)
	{
		if (i++ == target)
			return (random_sphere(light_list->content, point));
		light_list = light_list->next;
	}
	return (constant_vec3(0));
}

static size_t	count_list_size(const t_list *lst)
{
	size_t	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next != NULL)
		lst = (size++, lst->next);
	return (size);
}

static t_vec3	random_sphere(const t_sphere *sphere, const t_point3 *point)
{
	t_onb	onb;
	t_vec3	direct;
	double	squared_distance;

	direct = sub_vec3(sphere->center, *point);
	squared_distance = length_squared_vec3(direct);
	onb = construct_onb(direct);
	return (local_onb(onb, random_to_sphere(sphere->radius, squared_distance)));
}

static t_vec3	random_to_sphere(double radius, double squared_distance)
{
	t_vec3			vec;
	const double	u1 = random_double(0, 1);
	const double	u2 = random_double(0, 1);
	const double	phi = 2 * M_PI * u1;
	const double	cos_theta_max = sqrt(1 - pow(radius, 2) / squared_distance);

	vec.e[2] = 1 + u2 * (cos_theta_max - 1);
	vec.e[0] = cos(phi) * sqrt(1 - pow(vec.e[2], 2));
	vec.e[1] = sin(phi) * sqrt(1 - pow(vec.e[2], 2));
	return (vec);
}
