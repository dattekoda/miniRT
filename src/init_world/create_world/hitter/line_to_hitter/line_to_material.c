/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:54:31 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 16:05:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_info.h"
#include "material.h"
#include "element.h"
#include "init_world_utils.h"
#include "init_world_define.h"
#include "vec_utils.h"
#include <stddef.h>

static enum e_mat_idx	str_to_material_idx(const char *str);
static enum e_texture_idx	str_to_texture_idx(const char *str);

/*
@brief if line doesn't have any material nor texture info 
then set their default material and texture.
*/
int	line_to_material
	(const char *line, size_t *line_idx, 
		t_material **mat_pp, const t_element *element)
{
	t_color	raw_color;
	char	*mat_str;
	char	*tex_str;

	token_to_vec(line, line_idx, &raw_color);
	token_to_str(line, line_idx, &mat_str);
	token_to_str(line, line_idx, &tex_str);
	*mat_pp = param_to_material_ptr
		(normalize_color(raw_color), tex_str, mat_str, element);
	if (!*mat_pp)
		return (FAILURE);
	return (SUCCESS);
}

t_material	*parm_to_material_ptr
	(t_color color, char *tex_str, char *mat_str, const t_element *element)
{
	t_material			*mat_ptr;
	t_texture			*texture_ptr;
	enum e_mat_idx		mat_idx;
	enum e_texture_idx	texture_idx;

	if (!mat_str)
		texture_idx = element->material_idx;
	else
		texture_idx = str_to_texture_idx(tex_str);
	texture_ptr = g_gen_texture_table[texture_idx](color);
	if (!texture_ptr)
		return (NULL);
	if (!mat_str)
		mat_idx = element->material_idx;
	else
		mat_idx = str_to_material_idx(mat_str);
	mat_ptr = g_gen_material_table[mat_idx](texture_ptr);
	if (!mat_ptr)
		return (texture_ptr->clear(texture_ptr), FAILURE);
	return (SUCCESS);
}

/*
@brief if match str in specifiers then return valid idx
@return if str was invalid then returen -1
*/
static int str_to_idx(const char *str, const char *specifiers[])
{
	int	idx;

	idx = 0;
	while (specifiers[idx])
	{
		if (ft_strncmp(specifiers[idx], str, ft_strlen(specifiers[idx])) == 0)
			return (idx);
		idx++;
	}
	return (-1);
}

static enum e_mat_idx	str_to_material_idx(const char *str)
{
	return (str_to_idx(str, g_material_specifiers));
}

enum e_texture_idx	str_to_texture_idx(const char *str)
{
	return (str_to_idx(str, g_texture_specifiers));
}
