/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixture_pdf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:04:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:19:11 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIXTURE_PDF_H
# define MIXTURE_PDF_H

# include "pdf.h"

# define MIXTURE_RATIO 0.5

typedef struct s_mixture_pdf
{
	t_pdf	pdf;
	t_pdf	*surface_pdf;
	t_pdf	*light_pdf;
}	t_mixture_pdf;

t_mixture_pdf	construct_mixture_pdf(void *surface_pdf, void *light_pdf);

#endif
