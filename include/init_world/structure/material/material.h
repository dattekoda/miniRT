/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:45:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 16:19:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "hitter.h"
# include "texture.h"
# include "world.h"
# include "pdf.h"

/*
@brief ray_color() {
	// ...
	return (emmited + attenuation * ray_color(next_ray,...) * surface_pdf / sampling_pdf);
	}
*/
typedef struct s_scatter_record
{
	t_color	attenuation;
	t_ray	next_ray;
	double	surface_pdf;
	double	sampling_pdf;
}	t_srec;

typedef struct s_material
{
	bool		(*scatter)(const void *self, const t_world *world, t_hrec *hrec, t_srec *srec);
	t_color		(*emitted)(const void *self, t_hrec *hrec);
	t_texture	*texture_ptr;
	t_clear		clear;
}	t_material;

enum e_mat_idx
{
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	INVALID_MATERIAL_IDX
};

#endif
