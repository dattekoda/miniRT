/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_solid_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:05:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 00:17:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solid_texture.h"
#include "libft.h"

t_solid_texture			construct_solid_texture(t_color color);
static t_color			calc_solid_texture_value(
							const void *s,
							t_hrec *hrec);
void					clear_texture(void *s);
static t_texture		*clone_solid(void *s);

t_texture	*generate_solid_texture(t_color color)
{
	t_solid_texture	*p;

	p = ft_calloc(1, sizeof(t_solid_texture));
	if (!p)
		return (NULL);
	*p = construct_solid_texture(color);
	return ((t_texture *)p);
}

/*
@brief used at construct_checker(), so not static
*/
t_solid_texture	construct_solid_texture(t_color color)
{
	t_solid_texture	solid;

	solid.texture.calc_texture_value = calc_solid_texture_value;
	solid.color = color;
	solid.texture.clone = clone_solid;
	return (solid);
}

static t_texture	*clone_solid(void *s)
{
	const t_solid_texture	*self = s;
	t_solid_texture			*dst;

	dst = ft_calloc(1, sizeof(t_solid_texture));
	if (!dst)
		return (NULL);
	ft_memmove(dst, self, sizeof(t_solid_texture));
	return ((t_texture *)dst);
}

static t_color	calc_solid_texture_value(
					const void *s,
					t_hrec *hrec)
{
	const t_solid_texture	*self = s;

	(void)hrec;
	return (self->color);
}
