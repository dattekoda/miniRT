/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:14:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/20 17:39:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "light_pdf.h"
#include "vec_utils.h"

/*
@brief calc pdf to lights
*/
t_light_pdf	construct_light_pdf(const t_hrec *hrec, const t_world *world)
{
	t_light_pdf	light_pdf;

	// light_.pdf.value_pdf = value_light_pdf;
	// light_.pdf.random_pdf = random_light_pdf;
	light_pdf.light_list = world->light_list;
	light_pdf.point = hrec->point;
	return (light_pdf);
}

static double	value_light_pdf(const void *s, t_vec3 direct)
{
	t_light_pdf	*self;
	double		result;

	self = s;
	result = self->light_list.
}

static double	calc_light_pdf_value(const t_list *light_list, t_point3 point, t_vec3 direction)
{
	t_hitter	*hitter;
	double		pdf_value;

	pdf_value = 0;
	while (light_list)
	{
		hitter = light_list->content;
		pdf_value += light_list->
		light_list = light_list->next;
	}
}

static double	pdf_value_sphere(t_sphere *sphere, t_point3 point, t_vec3 direction)
{
	t_hit_record	rec;
	t_range			range = construct_vec2()
}
