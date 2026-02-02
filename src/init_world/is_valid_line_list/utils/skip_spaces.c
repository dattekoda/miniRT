/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:48:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:20:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "line_reader.h"
#include <stddef.h>

t_result	skip_spaces(t_line_reader *line_reader)
{
	if (lr_getc(line_reader) != ' ' && lr_getc(line_reader) != '\t')
		return (construct_result("invalid format"));
	while (lr_getc(line_reader) == ' ' || lr_getc(line_reader) == '\t')
		line_reader->idx++;
	return (construct_result(NULL));
}
