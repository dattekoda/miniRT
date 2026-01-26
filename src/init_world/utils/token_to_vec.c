/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:00:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 22:16:54 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "validate_utils.h"
#include "vec.h"
#include "libft.h"

static t_result	skip_comma(const char *line, size_t *line_idx);

t_result	token_to_vec(const char *line, size_t *line_idx, t_vec3 *vec)
{
	t_result	result;
	size_t		e_idx;

	e_idx = 0;
	while (e_idx < 3)
	{
		result = token_to_value(line, line_idx, &vec->e[e_idx]);
		if (result.state == FAILURE)
			return (result);
		if (e_idx != 2)
			result = skip_comma(line, line_idx);
		if (result.state == FAILURE)
			return (result);
		e_idx++;
	}
	return (construct_result(NULL));
}

static t_result	skip_comma(const char *line, size_t *line_idx)
{
	skip_spaces(line, line_idx);
	if (line[*line_idx] != ',')
		return (construct_result("need ','"));
	(*line_idx)++;
	return (construct_result(NULL));
}
