/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixture_pdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:04:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/21 16:52:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mixture_pdf.h"
#include "rt_utils.h"
#include "vec_utils.h"
#include "libft.h"

static double	calc_mixture_pdf_value(const void *s, const t_vec3 *direction);
static t_vec3	generate_mixture_pdf_direction(const void *s);

t_mixture_pdf	construct_mixture_pdf(
					const void *surface_pdf,
					const t_light_pdf *light_pdf)
{
	t_mixture_pdf	mixture;

	ft_bzero(&mixture, sizeof(t_mixture_pdf));
	mixture.surface_pdf = surface_pdf;
	mixture.light_pdf = light_pdf;
	mixture.pdf.calc_pdf_value = calc_mixture_pdf_value;
	mixture.pdf.generate = generate_mixture_pdf_direction;
	
	return (mixture);
}

#include "rt_debug.h"
#include <stdio.h>
static double	calc_mixture_pdf_value(const void *s, const t_vec3 *direction)
{
	const t_mixture_pdf	*self = s;
	const t_pdf			*surface_pdf = self->surface_pdf;
	const t_light_pdf	*light_pdf = self->light_pdf;

	if (!light_pdf->light_list)
		return (surface_pdf->calc_pdf_value(surface_pdf, direction));
	return (MIXTURE_LIGHT_RATIO
		* surface_pdf->calc_pdf_value(surface_pdf, direction)
		+ (1.0 - MIXTURE_LIGHT_RATIO)
		* light_pdf->pdf.calc_pdf_value(light_pdf, direction));
}

void	print_hitter_list(const t_list *list); // debug

static t_vec3	generate_mixture_pdf_direction(const void *s)
{
	const t_mixture_pdf	*self = s;
	const t_pdf			*surface_pdf = self->surface_pdf;
	const t_light_pdf	*light_pdf = self->light_pdf;

	if (light_pdf->light_list && random_01() < MIXTURE_LIGHT_RATIO)
		return (light_pdf->pdf.generate(light_pdf));
	return (surface_pdf->generate(surface_pdf));
	
}
