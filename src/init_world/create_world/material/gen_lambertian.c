/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_lambertian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:36:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 14:49:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"
#include "result.h"
#include "libft.h"

static t_lambertian	construct_lambertian(t_texture *texture_p);
void				clear_material(void *s);

t_lambertian	*gen_lambertian(t_texture *texture_p)
{
	t_lambertian	*p;

	if (!texture_p)
		return (NULL);
	p = ft_calloc(1, sizeof(t_lambertian));
	if (!p)
		return (texture_p->clear(texture_p), NULL);
	*p = construct_lambertian(texture_p);
	return (p);
}

static t_lambertian	construct_lambertian(t_texture *texture_p)
{
	t_lambertian	lambertian;

	lambertian.material.scatter = scatter_lambertian;
	lambertian.material.clear = clear_material;
	lambertian.material.texture_p = texture_p;
}

static bool	scatter_lambertian(const void *s, t_hrec *hrec, t_srec *srec)
{
	
	return (SUCCESS);
}

void	clear_material(void *s)
{
	t_material	*self;

	self = s;
	self->texture_p->clear(self->texture_p);
	free(self);
}
