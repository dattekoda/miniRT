/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:57:26 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/02 18:34:14 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include <stdlib.h>

t_material	*clone_material(const void *s)
{
	const t_material	*self = s;
	t_texture			*texture_p;
	void				*dst;

	texture_p = clone_texture(self->texture_ptr);
	if (!texture_p)
		return (NULL);
	dst = ft_calloc(1, self->size);
	if (!dst)
	{
		free(texture_p);
		return (NULL);
	}
	ft_memmove(dst, self, self->size);
	((t_material *)dst)->texture_ptr = texture_p;
	return ((t_material *)dst);
}
