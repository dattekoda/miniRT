/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_vec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:00:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils_bonus.h"
#include "validate_utils_bonus.h"
#include "vec_bonus.h"
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
