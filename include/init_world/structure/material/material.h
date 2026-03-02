/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:45:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/02 18:48:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "scatter_record.h"
# include "hit_record.h"
# include "rt_utils.h"
# include "texture.h"
# include "world.h"
# include "pdf.h"
# include <stdbool.h>

typedef enum e_material_idx
{
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	INVALID_MATERIAL_IDX
}	t_material_idx;

typedef struct s_material
{
	bool							(*scatter)(
		const void *self,
		const t_world * world,
		t_hrec * hrec,
		t_srec * srec);
	t_texture						*texture_ptr;
	t_pdf							*pdf_ptr;
	t_clear							clear;
	t_material_idx					idx;
	size_t							size;
}	t_material;

t_material	*clone_material(const void *s);

#endif
