/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:54:31 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 10:44:40 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_info.h"
#include "material.h"
#include "element.h"
#include "init_world_utils.h"
#include "init_world_define.h"
#include "vec_utils.h"
#include <stddef.h>

static t_material_info	line_to_material_info
	(const char *line, size_t *i_ptr, t_element element);
static int				info_to_material
	(t_material_info info, t_material **mat_ptr_ptr);

/*
@brief if line doesn't have any material nor texture info 
then set their default material and texture.
*/
int	line_to_material
	(const char *line, size_t *i_ptr, t_material **mat_ptr_ptr, t_element element)
{
	t_material_info	info;

	info = line_to_material_info(line, i_ptr, element);
	if (info_to_material(info, mat_ptr_ptr) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*
@detail no need free(texture_ptr) when generate_material failed because
gen mat responsible for free(texture_ptr)
*/
static int	info_to_material(t_material_info info, t_material **mat_ptr_ptr)
{
	t_texture	*texture_ptr;
	
	texture_ptr = g_generate_textures[info.tex_idx](info.color);
	if (!texture_ptr)
		return (FAILURE);
	*mat_ptr_ptr = g_generate_materials[info.mat_idx](texture_ptr);
	if (!*mat_ptr_ptr)
		return (FAILURE);
	return (SUCCESS);
}

static t_material_info	line_to_material_info
	(const char *line, size_t *i_ptr, t_element element)
{
	t_material_info	info;
	t_color			raw_color;
	char			c;

	ft_bzero(&info, sizeof(t_material_info));
	token_to_vec(line, i_ptr, &raw_color);
	info.color = normalize_color(raw_color);
	token_to_char(line, i_ptr, &c);
	info.mat_idx = char_to_material_idx(c, element.material_idx);
	token_to_char(line, i_ptr, &c);
	info.tex_idx = char_to_material_idx(c, element.texture_idx);
	return (info);
}
