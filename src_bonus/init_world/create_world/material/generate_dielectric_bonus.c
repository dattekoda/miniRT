/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_dielectric_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:28:52 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 23:04:11 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dielectric_bonus.h"
#include "rt_utils_bonus.h"
#include "rt_config_bonus.h"
#include "vec_utils_bonus.h"
#include <math.h>
#include <stdlib.h>

t_vec3				refract(
						const t_vec3 unit_ray_in_direct,
						const t_vec3 normal,
						double refract_ratio);
static t_dielectric	construct_dielectric(t_texture *texture_ptr);
static bool			scatter_dielectric(
						const void *s,
						t_render_task *r_task,
						t_hrec *hrec,
						t_srec *srec);
static void			record_next_direct(
						const t_dielectric *self,
						t_hrec *hrec,
						t_srec *srec);
static void			init_refract_ratio_outward_normal(
						double	*refract_ratio,
						t_vec3	*outward_normal,
						const t_dielectric *self,
						t_hrec *hrec);

/*
@brief responsinble for free(texture_ptr)
*/
t_material	*generate_dielectric(t_texture *texture_ptr)
{
	t_dielectric	*p;

	if (!texture_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_dielectric));
	if (!p)
	{
		free(texture_ptr);
		return (NULL);
	}
	*p = construct_dielectric(texture_ptr);
	return ((t_material *)p);
}

static t_dielectric	construct_dielectric(t_texture *texture_ptr)
{
	t_dielectric	dielectric;

	ft_bzero(&dielectric, sizeof(t_dielectric));
	dielectric.material.scatter = scatter_dielectric;
	dielectric.material.clear = clear_material;
	dielectric.material.size = sizeof(t_dielectric);
	dielectric.material.texture_ptr = texture_ptr;
	dielectric.material.idx = DIELECTRIC;
	dielectric.refract_idx = REFRACT_IDX;
	return (dielectric);
}

static bool	scatter_dielectric(
			const void *s,
			t_render_task *r_task,
			t_hrec *hrec,
			t_srec *srec)
{
	const t_dielectric	*self = s;

	(void)r_task;
	srec->attenuation = self->material.texture_ptr->calc_texture_value(
			self->material.texture_ptr, hrec);
	record_next_direct(self, hrec, srec);
	return (true);
}

static void	record_next_direct(
			const t_dielectric *self,
			t_hrec *hrec,
			t_srec *srec)
{
	const t_vec3		unit_direct = normalize_vec3(hrec->ray_in.direct);
	t_vec3				outward_normal;
	double				refract_ratio;
	double				sin_theta;

	init_refract_ratio_outward_normal(
		&refract_ratio, &outward_normal, self, hrec);
	sin_theta = sqrt(1.0 - pow(
				fmin(dot(negative_vec3(unit_direct), outward_normal), 1.0), 2));
	if (refract_ratio * sin_theta > 1.0)
		srec->next_ray
			= construct_ray(hrec->point, reflect(unit_direct, outward_normal));
	else
		srec->next_ray = construct_ray(hrec->point,
				refract(unit_direct, outward_normal, refract_ratio));
	srec->sampling_pdf = 1.0;
	srec->surface_pdf = 1.0;
	return ;
}

static void	init_refract_ratio_outward_normal(
	double	*refract_ratio,
	t_vec3	*outward_normal,
	const t_dielectric *self,
	t_hrec *hrec)
{
	if (dot(hrec->ray_in.direct, hrec->normal) < 0)
	{
		*refract_ratio = 1 / self->refract_idx;
		*outward_normal = hrec->normal;
	}
	else
	{
		*refract_ratio = self->refract_idx;
		*outward_normal = negative_vec3(hrec->normal);
	}
	return ;
}
