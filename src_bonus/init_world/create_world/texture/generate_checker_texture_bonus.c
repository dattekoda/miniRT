/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_checker_texture_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:01:59 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_texture_bonus.h"
#include "solid_texture_bonus.h"
#include "vec_utils_bonus.h"
#include "rt_utils_bonus.h"
#include "rt_define_bonus.h"
#include "libft.h"
#include <math.h>

t_solid_texture				construct_solid_texture(t_color color);
static t_color				calc_checker_texture_value(
								const void *s,
								t_hrec *hrec);
static t_checker_texture	construct_checker_texture(
								t_color color);

// TODO: To stay consistent with generate_*_texture() functions, 
// we need to rename the material-related functions to generate_*_material().
t_texture	*generate_checker_texture(t_color color)
{
	t_checker_texture	*p;

	p = ft_calloc(1, sizeof(t_checker_texture));
	if (!p)
		return (NULL);
	*p = construct_checker_texture(color);
	return ((t_texture *)p);
}

static t_checker_texture	construct_checker_texture(
								t_color color)
{
	t_checker_texture	check;

	check.texture.calc_texture_value = calc_checker_texture_value;
	check.texture.size = sizeof(t_checker_texture);
	check.even = construct_solid_texture(color);
	check.odd = construct_solid_texture(
			construct_vec3(R_CHECKER, G_CHECKER, B_CHECKER));
	return (check);
}

static t_color	calc_checker_texture_value(
					const void *s,
					t_hrec *hrec)
{
	const t_checker_texture	*self = s;
	const int				ui
		= (int)floor(hrec->map.e[1] * CHECKER_SPLIT_SIZE);
	const int				vi
		= (int)floor(hrec->map.e[0] * CHECKER_SPLIT_SIZE);

	if ((ui + vi) & 1)
		return (self->odd.texture.calc_texture_value(&self->odd, hrec));
	return (self->even.texture.calc_texture_value(&self->even, hrec));
}
