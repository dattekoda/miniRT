/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:12:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/02 18:28:29 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "libft.h"

t_texture	*clone_texture(const void *s)
{
	const t_texture		*self = s;
	void				*dst;

	dst = ft_calloc(1, self->size);
	if (!dst)
		return (NULL);
	return (ft_memmove(dst, self, self->size));
}
