/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_lambertian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:36:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 17:26:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"
#include "mixture_pdf.h"
#include "light_pdf.h"
#include "cosine_pdf.h"
#include "vec_utils.h"
#include "ray.h"
#include "result.h"
#include "libft.h"

static t_lambertian		construct_lambertian(t_texture *texture_p);
void					clear_material(void *s);
static t_mixture_pdf	create_mix_pdf_lambertian(const t_world *world, const t_hrec *hrec);

t_lambertian	*generate_lambertian(t_texture *texture_p)
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

static bool	scatter_lambertian(const void *s, const t_world *world, t_hrec *hrec, t_srec *srec)
{
	const t_lambertian	*self;
	t_mixture_pdf		mix_pdf;
	t_texture			*texture_p;

	self = s;
	texture_p = self->material.texture_p;
	srec->attenuation = texture_p->texture_value(texture_p, hrec);
	mix_pdf = create_mix_pdf_lambertian(world, hrec);
	srec->next_ray = construct_ray(hrec->point, mix_pdf.pdf.random_pdf(&mix_pdf));
	srec->sampling_pdf = mix_pdf.pdf.value_pdf(&mix_pdf, srec->next_ray.direct);
	srec->surface_pdf = mix_pdf.surface_pdf->value_pdf(&mix_pdf.surface_pdf, srec->next_ray.direct);
	return (true);
}

static t_mixture_pdf	create_mix_pdf_lambertian(const t_world *world, const t_hrec *hrec)
{
	t_mixture_pdf		mix_pdf;
	t_light_pdf			light_pdf;
	t_cosine_pdf		cos_pdf;
	t_vec3				reflect_normal;

	if (dot(hrec->normal, hrec->ray_in.direct) > 0)
		reflect_normal = negative_vec3(hrec->normal);
	else
		reflect_normal = hrec->normal;
	cos_pdf = construct_cosine_pdf(reflect_normal);
	light_pdf = construct_light_pdf(hrec, world);
	mix_pdf = construct_mixture_pdf(&cos_pdf, &light_pdf);
	return (mix_pdf);
}
