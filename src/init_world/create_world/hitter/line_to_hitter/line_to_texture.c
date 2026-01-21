/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:54:31 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/21 18:00:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "element.h"
#include "init_world_utils.h"
#include "vec_utils.h"
#include <stddef.h>

/*
@brief if found material and texture specifier then set them correctly.
Unless, set element's default material and texture.
@note used by only line_to_*
*/
int	line_to_material(const char *line, size_t i, 
	t_material *mat_ptr, t_element element)
{
	t_texture	*texture_ptr;
	t_color		raw_color;
	char		c;

	token_to_vec(line, &i, &raw_color);
	token_to_char(line, &i, &c);
	texture_ptr = 
		g_generate_textures
			[char_to_texture_idx(c, element.texture_id)]
			(normalize_color(raw_color));
	if (!texture_ptr)
		return (FAILURE);
	token_to_char(line, &i, &c);
	mat_ptr = 
		g_generate_materials
			[char_to_material_idx(c, element.material_id)]
			(texture_ptr);
	if (!mat_ptr)
		return (texture_ptr->clear(texture_ptr), FAILURE);
	return (SUCCESS);
}