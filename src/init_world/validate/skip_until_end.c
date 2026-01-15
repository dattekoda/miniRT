/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_until_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:50:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 13:00:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"

t_result	skip_until_end(const char *line, size_t *line_idx)
{
	skip_spaces(line, line_idx);
	if (line[*line_idx] != '\0' && line[*line_idx] != '\n')
		return (construct_result("invalid end"));
	return (construct_result(NULL));
}
