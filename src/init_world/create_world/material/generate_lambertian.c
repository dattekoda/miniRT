/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_lambertian.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:43:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/27 23:04:44 by khanadat         ###   ########.fr       */
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
#include <stdlib.h>

t_vec3					orient_normal(
							const t_vec3 *hrec_normal, 
							const t_vec3 *ray_in_direct);
void					clear_material(void *s);
static t_lambertian		construct_lambertian(t_texture *texture_ptr);
static bool				scatter_lambertian(
							const void *s,
							const t_world *world,
							t_hrec *hrec,
							t_srec *srec);
static void				record_next_direct_from_pdf(
							const t_list *light_list,
							const t_hrec *hrec,
							t_srec *srec);

/*
@brief responsible for free(texture_ptr)
*/
t_material	*generate_lambertian(t_texture *texture_ptr)
{
	t_lambertian	*p;

	if (!texture_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_lambertian));
	if (!p)
	{
		free(texture_ptr);
		return (NULL);
	}
	*p = construct_lambertian(texture_ptr);
	return ((t_material *)p);
}

static t_lambertian	construct_lambertian(t_texture *texture_ptr)
{
	t_lambertian	lambertian;

	ft_bzero(&lambertian, sizeof(t_lambertian));
	lambertian.material.scatter = scatter_lambertian;
	lambertian.material.clear = clear_material;
	lambertian.material.texture_ptr = texture_ptr;
	lambertian.material.idx = LAMBERTIAN;
	return (lambertian);
}

#include <stdio.h>
static bool	scatter_lambertian(
				const void *s,
				const t_world *world,
				t_hrec *hrec,
				t_srec *srec)
{
	const t_lambertian	*self = s;

	srec->attenuation
		= self->material.texture_ptr->calc_texture_value(
			self->material.texture_ptr,
			hrec);
	record_next_direct_from_pdf(world->light_list, hrec, srec);
	return (true);
}

void	print_hitter_list(const t_list *list);

static void		record_next_direct_from_pdf(
				const t_list *light_list,
				const t_hrec *hrec,
				t_srec *srec)
{
	const t_vec3		reflect_normal
		= orient_normal(&hrec->normal, &hrec->ray_in.direct);
	const t_cosine_pdf	cos_pdf
		= construct_cosine_pdf(reflect_normal);
	const t_light_pdf	light_pdf
		= construct_light_pdf(hrec, light_list);
	const t_mixture_pdf	mix_pdf
		= construct_mixture_pdf(&cos_pdf, &light_pdf);

	srec->next_ray = construct_ray(
			hrec->point, mix_pdf.pdf.generate(&mix_pdf));
	srec->sampling_pdf = mix_pdf.pdf.calc_pdf_value(
			&mix_pdf, &srec->next_ray.direct);
	srec->surface_pdf = mix_pdf.surface_pdf->calc_pdf_value(
			mix_pdf.surface_pdf, &srec->next_ray.direct);

	// printf("light pdf: %f\n", light_pdf.pdf.calc_pdf_value(&light_pdf.pdf, &srec->next_ray.direct)); // debug
	return ;
}
