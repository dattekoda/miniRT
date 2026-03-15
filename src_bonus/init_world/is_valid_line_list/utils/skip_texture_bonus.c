/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:35:19 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils_bonus.h"
#include "init_world_utils_bonus.h"
#include "result_bonus.h"
#include "rt_define_bonus.h"
#include "libft.h"
#include <stddef.h>

t_result	skip_texture(const char *line, size_t *line_idx)
{
	t_result	result;
	char		*str;

	result = skip_spaces(line, line_idx);
	if (result.state == FAILURE)
		return (result);
	result = token_to_str(line, line_idx, &str);
	if (result.state == FAILURE)
		return (result);
	if (str_to_texture_idx(str) == INVALID_TEXTURE_IDX)
	{
		(*line_idx)--;
		return (construct_result(
				"texture specifier should be: solid checker bump"));
	}
	return (construct_success_result());
}
