/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine_pdf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosine_pdf_bonus.h"
#include "vec_utils_bonus.h"
#include "rt_utils_bonus.h"
#include "rt_define_bonus.h"
#include "axis_bonus.h"
#include "libft.h"
#include <math.h>

static double	calc_cosine_pdf_value(
					const void *s,
					const t_vec3 *direction);
static t_vec3	generate_cosine_pdf_direction(const void *s);
static t_vec3	random_cosine_direction(void);

t_cosine_pdf	construct_cosine_pdf(t_vec3 normal)
{
	t_cosine_pdf	cosine;

	cosine.onb = construct_onb(normal);
	cosine.pdf.calc_pdf_value = calc_cosine_pdf_value;
	cosine.pdf.generate = generate_cosine_pdf_direction;
	return (cosine);
}

static double	calc_cosine_pdf_value(
					const void *s,
					const t_vec3 *direction)
{
	const t_cosine_pdf	*self = s;
	const double		cosine
		= dot(normalize_vec3(*direction), self->onb.v[A_Z]);

	if (cosine < 0)
		return (0);
	return (cosine / M_PI);
}

static t_vec3	generate_cosine_pdf_direction(const void *s)
{
	return (local_onb(
			((const t_cosine_pdf *)s)->onb,
			random_cosine_direction()));
}

static t_vec3	random_cosine_direction(void)
{
	const double	r1 = random_01();
	const double	r2 = random_01();
	const double	phi = 2 * M_PI * r1;

	return (construct_vec3(
			cos(phi) * sqrt(r2),
			sin(phi) * sqrt(r2),
			sqrt(1 - r2)));
}
