/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:45:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 15:41:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "hitter.h"
# include "texture.h"

typedef struct s_scatter_record
{
	t_color	attenuation;
	t_ray	specular_ray;
}	t_srec;

typedef struct s_material
{
	int			(*scatter)(const void *self, const t_hrec *hrec, t_srec *srec);
	t_texture	*texture_p;
	t_clear		clear;
}	t_material;

#endif
