/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:34:25 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/25 11:22:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "rt_utils.h"
#include "vec_utils.h"

static t_light	construct_light(t_texture *texture_ptr);
static t_color	emmited_light(const void *s, t_hrec *hrec);
static bool		scatter_light(const void *s, const t_world *world, t_hrec *hrec, t_srec *srec);

/*
@brief responsible for free(texture_ptr)
*/
t_material	*generate_light(t_texture *texture_ptr)
{
	t_light	*light_ptr;

	if (!texture_ptr)
		return (NULL);
	light_ptr = ft_calloc(1, sizeof(t_light));
	if (!light_ptr)
		return (texture_ptr->clear(texture_ptr), NULL);
	*light_ptr = construct_light(texture_ptr);
	return ((t_material *)light_ptr);
}

static t_light	construct_light(t_texture *texture_ptr)
{
	t_light	light;

	ft_bzero(&light, sizeof(t_light));
	light.material.scatter = scatter_light;
	light.material.emitted = emmited_light;
	light.material.texture_ptr = texture_ptr;
	light.material.clear = clear_material;
	return (light);
}

static t_color	emmited_light(const void *s, t_hrec *hrec)
{
	const t_light	*self;
	t_texture		*texture_ptr;

	self = s;
	texture_ptr = self->material.texture_ptr;
	if (dot(hrec->normal, hrec->ray_in.direct) > 0)
		return (construct_vec3(1.0, 0.0, 0.0));
	return (texture_ptr->calc_texture_value(texture_ptr, hrec));
}

static bool	scatter_light(const void *s, const t_world *world, t_hrec *hrec, t_srec *srec)
{
	(void)s;
	(void)world;
	(void)hrec;
	(void)srec;
	return (false);
}
