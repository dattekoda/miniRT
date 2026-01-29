/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine_pdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:21:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosine_pdf.h"

t_cosine_pdf	construct_cosine_pdf(t_vec3 normal)
{
	t_cosine_pdf	cos_;

	cos_.normal = normal;
	// cos_.pdf.calc_pdf_value = value_cos_pdf;
	// cos_.pdf.random_pdf = random_cos_pdf;
	return (cos_);
}
