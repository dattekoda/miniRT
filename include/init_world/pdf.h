/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:07:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/24 22:08:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PDF_H
# define PDF_H

# include "vec.h"

/*
@param value_pdf ほうこうべくとるにおうじてかくりつみつどをかえす
@param random_pdf そのpdf にそう ほうこうべくせいせい*/
typedef struct s_pdf
{
	double	(*calc_pdf_value)(const void *self, t_vec3 direction);
	t_vec3	(*random_pdf)(const void *self);
}	t_pdf;

#endif
