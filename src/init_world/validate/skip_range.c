/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:05:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 19:16:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"

t_result	skip_range(const char *line, size_t *line_idx, \
double min, double max)
{
	t_result	result;
	double		d;

	result = skip_spaces(line, line_idx);
	if (result.state == FAILURE)
		return (result);
	result = line_to_value(line, line_idx, &d);
	if (result.state == FAILURE)
		return (result);
	if (d < min || max < d)
	{
		(*line_idx)--;
		return (construct_result("out of range"));
	}
	return (construct_result(NULL));
}
