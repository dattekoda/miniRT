/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:07:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PDF_H
# define PDF_H

# include "vec.h"

typedef struct s_pdf
{
	double	(*value_pdf)(void *self, t_vec3 direction);
	t_vec3	(*random_pdf)(void *self);
}	t_pdf;

#endif
