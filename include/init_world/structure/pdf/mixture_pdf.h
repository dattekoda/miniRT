/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixture_pdf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:04:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 21:52:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIXTURE_PDF_H
# define MIXTURE_PDF_H

# include "pdf.h"

# define MIXTURE_RATIO 0.5

typedef struct s_mixture_pdf
{
	t_pdf		pdf;
	const t_pdf	*surface_pdf;
	const t_pdf	*light_pdf;
}	t_mixture_pdf;

t_mixture_pdf	construct_mixture_pdf(
					const void *surface_pdf,
					const void *light_pdf);

#endif
