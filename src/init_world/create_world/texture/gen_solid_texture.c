/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_solid_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:05:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 16:59:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solid_texture.h"
#include "libft.h"

static t_solid_texture	construct_solid_texture(t_color color);
static t_color			texture_value_solid(void *s, t_hrec *hrec);
void					clear_texture(void *s);

t_solid_texture	*gen_solid_texture(t_color color)
{
	t_solid_texture	*p;

	p = ft_calloc(1, sizeof(t_solid_texture));
	if (!p)
		return (NULL);
	*p = construct_solid_texture(color);
}

static t_solid_texture	construct_solid_texture(t_color color)
{
	t_solid_texture	solid;

	solid.texture.texture_value = texture_value_solid;
	solid.texture.clear = clear_texture;
	solid.color = color;
	return (solid);
}

static t_color	texture_value_solid(void *s, t_hrec *hrec)
{
	t_solid_texture	*self;

	self = s;
	(void)hrec;
	return (self->color);
}

void	clear_texture(void *s)
{
	free(s);
}
