/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine_pdf_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:29:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:54:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COSINE_PDF_BONUS_H
# define COSINE_PDF_BONUS_H

# include "pdf_bonus.h"
# include "vec_bonus.h"

typedef struct s_cosine_pdf
{
	t_pdf	pdf;
	t_onb	onb;
}	t_cosine_pdf;

// t_cosine_pdf	*generate_cosine_pdf(t_vec3 normal);
t_cosine_pdf	construct_cosine_pdf(t_vec3 normal);

#endif
