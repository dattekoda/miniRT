/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_idx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:45:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 16:35:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <stddef.h>

static int str_to_idx(const char *str, const char *specifiers[]);

enum e_mat_idx	str_to_material_idx(const char *str)
{
	int	idx;

	idx = str_to_idx(str, g_material_specifiers);
	if (idx == -1)
		return (INVALID_MATERIAL_IDX);
	return (idx);
}

enum e_texture_idx	str_to_texture_idx(const char *str)
{
	int	idx;

	idx = str_to_idx(str, g_texture_specifiers);
	if (idx == -1)
		return (INVALID_TEXTURE_IDX);
	return (idx);
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
