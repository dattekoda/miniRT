/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:05:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:23:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "init_world_utils.h"
#include "line_reader.h"

t_result	skip_range(t_line_reader *line_reader,
	double min, double max)
{
	t_result	result;
	double		d;

	result = skip_spaces(line_reader);
	if (result.state == FAILURE)
		return (result);
	result = token_to_value(line_reader, &d);
	if (result.state == FAILURE)
		return (result);
	if (d < min || max < d)
	{
		(line_reader->idx)--;
		return (construct_result("out of range"));
	}
	return (construct_result(NULL));
}
