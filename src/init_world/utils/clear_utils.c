/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:39:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 17:05:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"
#include "material.h"

void	clear_texture(void *s)
{
	free(s);
}

void	clear_premitive(void *self)
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
	if (self->texture_p)
		self->texture_p->clear(self->texture_p);
	free(self);
}
