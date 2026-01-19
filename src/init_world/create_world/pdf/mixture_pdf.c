/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixture_pdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:04:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 16:46:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mixture_pdf.h"

t_mixture_pdf	construct_mixture_pdf(void *surface_pdf, void *light_pdf)
{
	t_mixture_pdf	mixture;

	mixture.surface_pdf = surface_pdf;
	mixture.light_pdf = light_pdf;
	// mixture.pdf.value_pdf = value_mixure_pdf;
	// mixture.pdf.random_pdf = random_mixture_pdf;
	return (mixture);
}
