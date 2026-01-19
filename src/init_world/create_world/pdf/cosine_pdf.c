/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine_pdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 16:33:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosine_pdf.h"

t_cosine_pdf	construct_cosine_pdf(t_vec3 normal)
{
	t_cosine_pdf	cos_;

	cos_.normal = normal;
	// cos_.pdf.value_pdf = value_cos_pdf;
	// cos_.pdf.random_pdf = random_cos_pdf;
	return (cos_);
}