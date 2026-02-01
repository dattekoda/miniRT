/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_metal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:32:13 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/31 10:10:26 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"
#include "mixture_pdf.h"
#include "rt_utils.h"
#include "libft.h"
#include "rt_define.h"
#include "vec_utils.h"
#include <stdbool.h>

t_material	*generate_metal(t_texture *texture_ptr)
{
	t_metal	*metal_ptr;

	if (!texture_ptr)
		return (NULL);
	metal_ptr = ft_calloc(1, sizeof(t_metal));
	if (!metal_ptr)
	{
		texture_ptr->clear(texture_ptr);
		return (NULL);
	}
	*metal_ptr = construct_metal(texture_ptr);
	return ((t_material *)metal_ptr);
}

static t_metal	construct_metal(t_texture *texture_ptr)
{
	t_metal	metal;

	ft_bzero(&metal, sizeof(t_metal));
	metal.fuzz = METAL_FUZZINESS;
	metal.material.texture_ptr = texture_ptr;
	metal.material.clear = clear_material;
	metal.material.scatter = scatter_metal;
	return (metal);
}

static bool	scatter_metal(
				const void *s,
				const t_world *world,
				t_hrec *hrec,
				t_srec *srec)
{
	const t_metal	*self;
	t_mixture_pdf	mix_pdf;
	t_texture		*texture_ptr;

	self = s;
	texture_ptr = self->material.texture_ptr;
	mix_pdf = create_mix_pdf_metal(world, hrec);
}

t_mixture_pdf	create_mix_pdf_metal(
					const t_world *world,
					const t_hrec *hrec)
{
	t_vec3	reflect_normal;

	reflect_normal = orient_normal(&hrec->normal, &hrec->ray_in.direct);

}

/*
法線ベクトルの向きを整える関数
mixture_pdf.cへ追加したい。
*/
t_vec3	orient_normal(const t_vec3 *hrec_normal, t_vec3 *ray_in_direct)
{
	if (dot(*hrec_normal, *ray_in_direct) > 0)
		return (negative_vec3(*hrec_normal));
	return (*hrec_normal);
}
