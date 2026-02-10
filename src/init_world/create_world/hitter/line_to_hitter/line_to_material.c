/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:54:31 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/09 17:04:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "element.h"
#include "init_world_utils.h"
#include "init_world_define.h"
#include "vec_utils.h"
#include <stddef.h>

t_material	*param_to_material_ptr(
				t_color color,
				const char *texture_str,
				const char *material_str,
				const t_element *element);

/*
@brief if line doesn't have any material nor texture info 
then set their default material and texture.
*/
int	line_to_material(
		const char *line,
		size_t *line_idx,
		t_material **mat_pp,
		const t_element *element)
{
	t_color	raw_color;
	char	*material_str;
	char	*texture_str;

	token_to_vec(line, line_idx, &raw_color);
	token_to_str(line, line_idx, &material_str);
	token_to_str(line, line_idx, &texture_str);
	*mat_pp = param_to_material_ptr(
			normalize_color(raw_color),
			texture_str,
			material_str,
			element);
	if (!*mat_pp)
		return (FAILURE);
	return (SUCCESS);
}

t_material	*param_to_material_ptr(
				t_color color,
				const char *texture_str,
				const char *material_str,
				const t_element *element)
{
	t_texture			*texture_ptr;
	enum e_material_idx	material_idx;
	enum e_texture_idx	texture_idx;

	if (!texture_str)
		texture_idx = element->material_idx;
	else
		texture_idx = str_to_texture_idx(texture_str);
	texture_ptr = g_gen_texture_table[texture_idx](color);
	if (!texture_ptr)
		return (NULL);
	if (!material_str)
		material_idx = element->material_idx;
	else
		material_idx = str_to_material_idx(material_str);
	return (g_gen_material_table[material_idx](texture_ptr));
}
