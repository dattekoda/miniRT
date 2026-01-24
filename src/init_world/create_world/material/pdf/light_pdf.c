/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:14:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/24 23:06:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_pdf.h"

double	calc_light_pdf_value(const void *s, t_vec3 direct);
t_vec3	random_light_pdf(const void *s);

/*
@brief calc pdf to lights
*/
t_light_pdf	construct_light_pdf(const t_hrec *hrec, const t_world *world)
{
	t_light_pdf	light_;

	light_.pdf.calc_pdf_value = calc_light_pdf_value;
	light_.pdf.random_pdf = random_light_pdf;
	light_.light_list = world->light_list;
	light_.point = hrec->point;
	return (light_);
}
