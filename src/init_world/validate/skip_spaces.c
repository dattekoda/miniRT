/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:48:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 00:07:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"

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
