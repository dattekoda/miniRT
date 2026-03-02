/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_dielectric.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:28:52 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/02 18:46:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dielectric.h"
#include "rt_utils.h"
#include "rt_config.h"
#include "vec_utils.h"
#include <math.h>
#include <stdlib.h>

static t_vec3		refract(
						const t_vec3 unit_ray_in_direct,
						const t_vec3 normal,
						double refract_ratio);
static t_dielectric	construct_dielectric(t_texture *texture_ptr);
static bool			scatter_dielectric(
						const void *s,
						const t_world *world,
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
			const t_world *world,
			t_hrec *hrec,
			t_srec *srec)
{
	const t_dielectric	*self = s;
	const t_vec3		unit_direct = normalize(hrec->ray_in.direct);
	double				refract_ratio;
	t_vec3				outward_normal;
	double				sin_theta;

	(void)world;
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
	srec->attenuation = self->material.texture_ptr->calc_texture_value(
			self->material.texture_ptr, hrec);
	srec->sampling_pdf = 1.0;
	srec->surface_pdf = 1.0;
	return (true);
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

static t_vec3	refract(
			const t_vec3 unit_ray_in_direct,
			const t_vec3 normal,
			double refract_ratio)
{
	const double	cos_theta = dot(negative_vec3(unit_ray_in_direct), normal);
	const t_vec3	next_ray_direct_parallel
		= scal_mul_vec3(
			add_vec3(
				unit_ray_in_direct,
				scal_mul_vec3(normal, cos_theta)),
			refract_ratio);
	const t_vec3	next_ray_direct_perp
		= scal_mul_vec3(
			normal,
			-sqrt(1 - length_squared_vec3(next_ray_direct_parallel)));

	return (add_vec3(next_ray_direct_parallel, next_ray_direct_perp));
}
