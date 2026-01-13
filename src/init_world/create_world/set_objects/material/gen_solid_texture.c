/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_solid_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:45:18 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/14 04:52:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solid_texture.h"
#include <stddef.h>

static t_solid_texture	construct_solid_texture(t_color color);
static t_color			texture_value_solid(void *s, t_point2 map, t_hrec *rec);

t_solid_texture	*gen_solid_texture(t_color color)
{
	t_solid_texture	*p = malloc(sizeof(*p));
	if (!p)
		return (NULL);
	*p = construct_solid_texture(color);
	return (p);
}

static t_solid_texture	construct_solid_texture(t_color color)
{
	t_solid_texture	solid;

	solid.texture.texture_value = texture_value_solid;
	solid.color = color;
	return (solid);
}

static t_color	texture_value_solid(void *s, t_point2 map, t_hrec *rec)
{
	t_solid_texture	*self;

	self = s;
	(void)map;
	(void)rec;
	return (self->color);
}
