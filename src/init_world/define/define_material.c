/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:55:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 16:23:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "material.h"
#include "texture.h"

t_material	*generate_lambertian(t_texture *texture_ptr);

const char *g_material_specifiers = {
	"lambertian",
	// "metal",
	// "dielectric",
	NULL,
};

const t_generate_material	g_gen_material_table[] = {
	generate_lambertian,
	NULL
};
