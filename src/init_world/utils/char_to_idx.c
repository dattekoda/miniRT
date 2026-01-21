/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:45:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/21 17:47:49 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include "libft.h"
#include <stddef.h>

static size_t	char_to_idx(char c, size_t default_idx, const char *specifiers);

size_t	char_to_material_idx(char c, size_t default_idx)
{
	return (char_to_idx(c, default_idx, MATERIAL_SPECIFIER));
}

size_t	char_to_texture_idx(char c, size_t default_idx)
{
	return (char_to_idx(c, default_idx, TEXTURE_SPECIFIER));
}

/*
@brief if hit c then return index or return default_idx
*/
static size_t	char_to_idx(char c, size_t default_idx, const char *specifiers)
{
	char	*strchr_result;

	strchr_result = ft_strchr(specifiers, c);
	if (strchr_result == NULL)
		return (default_idx);
	return ((size_t)(strchr_result - specifiers));
}
