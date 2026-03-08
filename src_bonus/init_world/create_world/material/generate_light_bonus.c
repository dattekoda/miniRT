/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_light_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:34:25 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:31:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_bonus.h"
#include "rt_utils_bonus.h"
#include "vec_utils_bonus.h"
#include <stdlib.h>

static t_light	construct_light(t_texture *texture_ptr);
static bool		scatter_light(
					const void *s,
					const t_world *world,
					t_hrec *hrec,
					t_srec *srec);

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
	{
		free(texture_ptr);
		return (NULL);
	}
	*light_ptr = construct_light(texture_ptr);
	return ((t_material *)light_ptr);
}

static t_light	construct_light(t_texture *texture_ptr)
{
	t_light	light;

	light.material.scatter = scatter_light;
	light.material.clear = clear_material;
	light.material.size = sizeof(t_light);
	light.material.texture_ptr = texture_ptr;
	return (light);
}

static bool	scatter_light(
				const void *s,
				const t_world *world,
				t_hrec *hrec,
				t_srec *srec)
{
	const t_texture		*texture_ptr
		= ((const t_light *)s)->material.texture_ptr;

	(void)world;
	if (dot(hrec->normal, hrec->ray_in.direct) > 0)
		srec->attenuation = construct_vec3(1.0, 0.0, 0.0);
	else
		srec->attenuation
			= texture_ptr->calc_texture_value(texture_ptr, hrec);
	return (false);
}
