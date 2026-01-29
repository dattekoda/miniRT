/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_solid_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:05:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 16:32:17 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solid_texture.h"
#include "libft.h"

static t_solid_texture	construct_solid_texture(t_color color);
static t_color			calc_solid_texture_value(const void *s, t_hrec *hrec);
void					clear_texture(void *s);

t_texture	*generate_solid_texture(t_color color)
{
	t_solid_texture	*p;

	p = ft_calloc(1, sizeof(t_solid_texture));
	if (!p)
		return (NULL);
	*p = construct_solid_texture(color);
	return ((t_texture *)p);
}

static t_solid_texture	construct_solid_texture(t_color color)
{
	t_solid_texture	solid;

	solid.texture.calc_texture_value = calc_solid_texture_value;
	solid.texture.clear = clear_texture;
	solid.color = color;
	return (solid);
}

static t_color	calc_solid_texture_value(const void *s, t_hrec *hrec)
{
	const t_solid_texture	*self;

	self = s;
	(void)hrec;
	return (self->color);
}
