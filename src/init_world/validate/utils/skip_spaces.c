/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:48:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 13:45:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <stddef.h>

t_result	skip_spaces(const char *line, size_t *line_idx)
{
	if (line[*line_idx] != ' ' && line[*line_idx] != '\t')
		return (construct_result("invalid format"));
	while (line[*line_idx] == ' ' || line[*line_idx] == '\t')
		(*line_idx)++;
	return (construct_result(NULL));
}

