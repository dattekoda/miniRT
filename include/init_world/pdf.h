/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:07:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 19:54:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PDF_H
# define PDF_H

typedef struct s_pdf
{
	double	(*value_pdf)(void *self);
	t_vec3	(*random_pdf)(void *self);
}	t_pdf;

#endif
