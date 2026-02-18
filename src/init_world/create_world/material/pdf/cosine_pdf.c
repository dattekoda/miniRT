/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine_pdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/13 19:48:57 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosine_pdf.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "rt_define.h"
#include "axis.h"
#include "libft.h"
#include <math.h>

static double	calc_cosine_pdf_value(
					const void *s,
					const t_vec3 *direction);
static t_vec3	generate_cosine_pdf_direction(const void *s);
static t_vec3	random_cosine_direction(void);

// t_cosine_pdf	*generate_cosine_pdf_direction(t_vec3 normal)
// {
// 	t_cosine_pdf	*p;

// 	p = ft_calloc(1, sizeof(t_cosine_pdf));
// 	if (!p)
// 		return (NULL);
// 	*p = construct_cosine_pdf(normal);
// 	return (p);
// }

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
			= dot(normalize(*direction), self->onb.v[A_Z]);

	if (cosine < 0)
		return (0);
	return (cosine / M_PI);
}

static t_vec3	generate_cosine_pdf_direction(const void *s)
{
	const t_cosine_pdf	*self = s;

	return (local_onb(self->onb, random_cosine_direction()));
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
