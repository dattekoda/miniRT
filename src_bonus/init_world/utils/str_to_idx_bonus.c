/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_idx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:45:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/09 16:27:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_define_bonus.h"
#include "texture_define_bonus.h"
#include "rt_define_bonus.h"
#include "libft.h"
#include <stddef.h>

static int		str_to_idx(const char *str, const char *specifiers[]);
static size_t	strlen_until_space(const char *str);

t_material_idx	str_to_material_idx(const char *str)
{
	int	idx;

	idx = str_to_idx(str, g_material_specifiers);
	if (idx == -1)
		return (INVALID_MATERIAL_IDX);
	return (idx);
}

t_texture_idx	str_to_texture_idx(const char *str)
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
static int	str_to_idx(const char *str, const char *specifiers[])
{
	int		idx;
	size_t	str_len;

	idx = 0;
	while (specifiers[idx])
	{
		str_len = strlen_until_space(str);
		if (ft_strncmp(specifiers[idx], str, str_len) == 0
			&& ft_strlen(specifiers[idx]) == str_len)
			return (idx);
		idx++;
	}
	return (-1);
}

static size_t	strlen_until_space(const char *str)
{
	const char	*start = str;

	while (str && !ft_strchr("\n\t ", *str))
		str++;
	return ((size_t)(str - start));
}
