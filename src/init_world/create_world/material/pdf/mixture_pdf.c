/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixture_pdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:04:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 20:07:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mixture_pdf.h"
#include "rt_utils.h"
#include "libft.h"

static double	calc_mixture_pdf_value(const void *s, const t_vec3 *direction);
static t_vec3	random_mixture_pdf(const void *s);

t_mixture_pdf	construct_mixture_pdf(void *surface_pdf, void *light_pdf)
{
	t_mixture_pdf	mixture;

	ft_bzero(&mixture, sizeof(t_mixture_pdf));
	mixture.surface_pdf = surface_pdf;
	mixture.light_pdf = light_pdf;
	mixture.pdf.calc_pdf_value = calc_mixture_pdf_value;
	mixture.pdf.random_pdf = random_mixture_pdf;
	return (mixture);
}

static double	calc_mixture_pdf_value(const void *s, const t_vec3 *direction)
{
	const t_mixture_pdf	*self = s;
	const t_pdf			*surface_pdf = self->surface_pdf;
	const t_pdf			*light_pdf = self->light_pdf;

	if (!light_pdf)
		return (surface_pdf->calc_pdf_value(surface_pdf, direction));
	return (MIXTURE_RATIO 
		* surface_pdf->calc_pdf_value(surface_pdf, direction) 
		+ (1.0 - MIXTURE_RATIO) 
		* light_pdf->calc_pdf_value(light_pdf, direction));
}

static t_vec3	random_mixture_pdf(const void *s)
{
	const t_mixture_pdf	*self = s;
	t_pdf				*surface_pdf = self->surface_pdf;
	t_pdf				*light_pdf = self->light_pdf;

	if (!light_pdf || random_double(0, 1) > MIXTURE_RATIO)
		return (surface_pdf->random_pdf(surface_pdf));
	return (light_pdf->random_pdf(light_pdf));
}
