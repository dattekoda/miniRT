/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:55:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define_bonus.h"
#include "material_define_bonus.h"
#include "texture_bonus.h"
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
