/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:14:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 16:30:23 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_pdf.h"

double	calc_light_pdf_value(const void *s, const t_vec3 *direct);
t_vec3	generate_light_pdf_direction(const void *s);

/*
@brief calc pdf to lights
*/
t_light_pdf	construct_light_pdf(const t_hrec *hrec, const t_list *light_list)
{
	t_light_pdf	light_;

	light_.pdf.calc_pdf_value = calc_light_pdf_value;
	light_.pdf.generate = generate_light_pdf_direction;
	light_.light_list = light_list;
	light_.point = hrec->point;
	return (light_);
}
