/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:05:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 16:34:17 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include <float.h>
#include <math.h>

static t_result	skip_range(const char *line, size_t *line_idx, \
double min, double max)
{
	t_result	result;
	double		d;

	result = skip_value(line, line_idx, IS_POINT, &d);
	if (result.state == FAILURE)
		return (result);
	if (d < min || max < d)
	{
		(*line_idx)--;
		return (construct_result("out of range"));
	}
	return (construct_result(NULL));
}

t_result	skip_lighting_ratio(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, 0.0, 1.0));
}

t_result	skip_fov(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, FLT_EPSILON, 180.0 - FLT_EPSILON));
}

t_result	skip_diameter(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, DBL_EPSILON, INFINITY));
}
