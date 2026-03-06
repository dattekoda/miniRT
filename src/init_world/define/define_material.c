/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:55:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/22 19:51:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "material_define.h"
#include "texture.h"
#include <stddef.h>

t_material	*generate_lambertian(t_texture *texture_ptr);
t_material	*generate_metal(t_texture *texture_ptr);
t_material	*generate_dielectric(t_texture *texture_ptr);

const char					*g_material_specifiers[] = {
	"lambertian",
	"metal",
	"dielectric",
	NULL,
};

const t_generate_material	g_gen_material_table[] = {
	generate_lambertian,
	generate_metal,
	generate_dielectric,
	NULL
};
