/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_metal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:32:13 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/02 18:40:01 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"
#include "mixture_pdf.h"
#include "rt_utils.h"
#include "libft.h"
#include "rt_define.h"
#include "vec_utils.h"
#include "light_pdf.h"
#include "cosine_pdf.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

t_vec3				orient_normal(
						const t_vec3 *hrec_normal,
						const t_vec3 *ray_in_direct);
static t_metal		construct_metal(t_texture *texture_ptr);
static t_vec3		random_in_unit_sphere(void);
static bool			scatter_metal(
						const void *s,
						const t_world *world,
						t_hrec *hrec,
						t_srec *srec);

/*
@brief responsible for free(texture_ptr)
*/
t_material	*generate_metal(t_texture *texture_ptr)
{
	t_metal	*metal_ptr;

	if (!texture_ptr)
		return (NULL);
	metal_ptr = ft_calloc(1, sizeof(t_metal));
	if (!metal_ptr)
	{
		free(texture_ptr);
		return (NULL);
	}
	*metal_ptr = construct_metal(texture_ptr);
	return ((t_material *)metal_ptr);
}

static t_metal	construct_metal(t_texture *texture_ptr)
{
	t_metal	metal;

	ft_bzero(&metal, sizeof(t_metal));
	metal.material.texture_ptr = texture_ptr;
	metal.material.scatter = scatter_metal;
	metal.material.clear = clear_material;
	metal.material.size = sizeof(t_metal);
	metal.material.idx = METAL;
	metal.fuzz = METAL_FUZZINESS;
	return (metal);
}

static bool	scatter_metal(
				const void *s,
				const t_world *world,
				t_hrec *hrec,
				t_srec *srec)
{
	const t_metal	*self = s;
	const t_vec3	reflect_normal
		= orient_normal(&hrec->normal, &hrec->ray_in.direct);
	const t_vec3	reflected
		= reflect(normalize(hrec->ray_in.direct), reflect_normal);
	const t_texture	*texture_ptr = self->material.texture_ptr;

	(void)world;
	srec->surface_pdf = 1.0;
	srec->sampling_pdf = 1.0;
	srec->attenuation = texture_ptr->calc_texture_value(texture_ptr, hrec);
	srec->next_ray = construct_ray(
			hrec->point,
			add_vec3(
				reflected,
				scal_mul_vec3(
					random_in_unit_sphere(),
					METAL_FUZZINESS)));
	return (true);
}

static t_vec3	random_in_unit_sphere(void)
{
	t_vec3	vec;

	while (1)
	{
		vec = construct_vec3(
				random_minus1_to_1(),
				random_minus1_to_1(),
				random_minus1_to_1());
		if (length_squared_vec3(vec) < 1)
			break ;
	}
	return (vec);
}
