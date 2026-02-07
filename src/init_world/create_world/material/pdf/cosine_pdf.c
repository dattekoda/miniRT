/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine_pdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:31:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 22:16:37 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosine_pdf.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "libft.h"
#include <math.h>

static double	calc_cosine_pdf_value(
					const void *s,
					const t_vec3 *direction);
static t_vec3	random_cosine_pdf(const void *s);
static t_vec3	random_cosine_direction(void);

t_cosine_pdf	*generate_cosine_pdf(t_vec3 normal)
{
	t_cosine_pdf	*p;

	p = ft_calloc(1, sizeof(t_cosine_pdf));
	if (!p)
		return (NULL);
	*p = construct_cosine_pdf(normal);
	return (p);
}

t_cosine_pdf	construct_cosine_pdf(t_vec3 normal)
{
	t_cosine_pdf	cosine;

	cosine.onb = construct_onb(normal);
	cosine.pdf.calc_pdf_value = calc_cosine_pdf_value;
	cosine.pdf.random_pdf = random_cosine_pdf;
	return (cosine);
}

static double	calc_cosine_pdf_value(
					const void *s,
					const t_vec3 *direction)
{
	const t_cosine_pdf	*self;

	self = s;
	return (dot(self->onb.v[2], normalize(*direction)));
}

static t_vec3	random_cosine_pdf(const void *s)
{
	t_cosine_pdf	*self;

	self = s;
	return (local_onb(self->onb, random_cosine_direction()));
}

static t_vec3	random_cosine_direction(void)
{
	t_vec3	direction;
	double	u1;
	double	u2;

	u1 = random_double(0, 1);
	u2 = random_double(0, 1);
	direction.e[0] = cos(2 * M_PI * u1) * sqrt(u2);
	direction.e[1] = sin(2 * M_PI * u1) * sqrt(u2);
	direction.e[2] = sqrt(1 - u2);
	return (direction);
}
