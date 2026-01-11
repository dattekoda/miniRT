/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:31:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 20:29:58 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "libft.h"

static t_result	skip_comma(const char *line, size_t *line_idx);

t_result	line_to_vec(const char *line, size_t *line_idx, double d3[3])
{
	t_result	result;
	size_t		d_idx;

	d_idx = 0;
	while (d_idx < 3)
	{
		result = line_to_value(line, line_idx, d3 + d_idx);
		if (result.state == FAILURE)
			return (result);
		if (d_idx != 2)
			result = skip_comma(line, line_idx);
		if (result.state == FAILURE)
			return (result);
		d_idx++;
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
