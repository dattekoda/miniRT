/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util_skip.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:11:50 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 18:12:38 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"

t_result	skip_spaces(const char *line, size_t *line_idx)
{
	if (line[*line_idx] != ' ' && line[*line_idx] != '\t')
		return (construct_result("invalid format"));
	while (line[*line_idx] == ' ' || line[*line_idx] == '\t')
		(*line_idx)++;
	return (construct_result(NULL));
}

t_result	skip_until_end(const char *line, size_t *line_idx)
{
	skip_spaces(line, line_idx);
	if (line[*line_idx] != '\0' && line[*line_idx] != '\n')
		return (construct_result("invalid ending"));
	return (construct_result(NULL));
}
