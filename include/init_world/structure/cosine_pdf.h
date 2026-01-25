/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine_pdf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:29:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 16:33:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COSINE_PDF_H
# define COSINE_PDF_H

# include "pdf.h"
# include "vec.h"

typedef struct s_cosine_pdf
{
	t_pdf	pdf;
	t_vec3	normal;
}	t_cosine_pdf;

t_cosine_pdf	construct_cosine_pdf(t_vec3 normal);

#endif
