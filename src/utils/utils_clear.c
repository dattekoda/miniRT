/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:39:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/20 16:40:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"
#include "material.h"

void	clear_texture(void *s)
{
	free(s);
}

void	clear_primitive(void *self)
{
	t_hitter	*hitter;

	hitter = (t_hitter *)self;
	if (hitter->mat_ptr)
		hitter->mat_ptr->clear(hitter->mat_ptr);
	hitter->mat_ptr = NULL;
	free(hitter);
}

void	clear_material(void *s)
{
	t_material	*self;

	self = s;
	if (self->texture_ptr)
		self->texture_ptr->clear(self->texture_ptr);
	self->texture_ptr = NULL;
	free(self);
}
