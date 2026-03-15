/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixture_pdf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:04:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIXTURE_PDF_BONUS_H
# define MIXTURE_PDF_BONUS_H

# include "pdf_bonus.h"
# include "light_pdf_bonus.h"

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
