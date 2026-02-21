/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixture_pdf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:04:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/21 16:52:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIXTURE_PDF_H
# define MIXTURE_PDF_H

# include "pdf.h"
# include "light_pdf.h"

# define MIXTURE_LIGHT_RATIO 0.5

typedef struct s_mixture_pdf
{
	t_pdf				pdf;
	const t_pdf			*surface_pdf;
	const t_light_pdf	*light_pdf;
}	t_mixture_pdf;

t_mixture_pdf	construct_mixture_pdf(
					const void *surface_pdf,
					const t_light_pdf *light_pdf);

#endif
