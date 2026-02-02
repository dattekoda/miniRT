/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:35:19 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/02 18:24:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "init_world_utils.h"
#include "result.h"
#include "rt_define.h"
#include "libft.h"
#include "line_reader.h"
#include <stddef.h>

t_result	skip_texture(t_line_reader *line_reader)
{
	t_result	result;
	char		*str;

	result = skip_spaces(line_reader);
	if (result.state == FAILURE)
		return (result);
	result = token_to_str(line_reader, &str);
	if (result.state == FAILURE)
		return (result);
	if (str_to_texture_idx(str) == INVALID_TEXTURE_IDX)
	{
		(line_reader->idx)--;
		return (construct_result(
				"texture specifier should be: solid checker bump"));
	}
	return (construct_result(NULL));
}
