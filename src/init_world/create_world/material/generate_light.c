/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:34:25 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/21 14:16:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "rt_utils.h"
#include "vec_utils.h"

static t_light	construct_light(t_texture *texture_ptr);
// static t_color	emmited_light(const void *s, t_hrec *hrec);
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
		return (texture_ptr->clear(texture_ptr), NULL);
	*light_ptr = construct_light(texture_ptr);
	return ((t_material *)light_ptr);
}

static t_light	construct_light(t_texture *texture_ptr)
{
	t_light	light;

	light.material.scatter = scatter_light;
	light.material.texture_ptr = texture_ptr;
	light.material.clear = clear_material;
	return (light);
}

#include <stdio.h>
static bool	scatter_light(
				const void *s,
				const t_world *world,
				t_hrec *hrec,
				t_srec *srec)
{
	const t_light		*self = s;
	const t_texture		*texture_ptr
		= self->material.texture_ptr;

	(void)world;
	if (dot(hrec->normal, hrec->ray_in.direct) > 0)
		srec->attenuation = construct_vec3(1.0, 0.0, 0.0);
	else
		srec->attenuation
		= texture_ptr->calc_texture_value(texture_ptr, hrec);
	printf("emmited color: %f %f %f\n", srec->attenuation.e[0], srec->attenuation.e[1], srec->attenuation.e[2]);
	return (false);
}
