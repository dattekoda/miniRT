/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:35:19 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/21 15:36:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "init_world_utils.h"
#include "result.h"
#include "rt_define.h"
#include "libft.h"
#include <stddef.h>

t_result	skip_texture(const char *line, size_t *line_idx)
{
	t_result	result;
	char		c;

	result = skip_spaces(line, line_idx);
	if (result.state == FAILURE)
		return (result);
	result = token_to_char(line, line_idx, &c);
	if (result.state == FAILURE)
		return (result);
	if (ft_strchr(TEXTURE_SPECIFIER, c) == NULL)
	{
		(*line_idx)--;
		return (construct_result(
			"texture specifier should be: "TEXTURE_SPECIFIER));
	}
	return (construct_result(NULL));
}
