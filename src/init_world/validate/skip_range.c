/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:05:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 00:06:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include <float.h>
#include <math.h>

static t_result	skip_range(const char *line, size_t *line_idx, \
	double min, double max)
{
	double	d;
	char	*endptr;

	d = ft_strtod(line + *line_idx, &endptr);
	if (endptr == line + *line_idx)
		return (construct_result("invalid format"));
	*line_idx = (endptr - line) - 1;
	if (isinf(d) || isnan(d))
		return (construct_result("invalid value"));
	if (d < min || max < d)
		return (construct_result("out of range"));
	*line_idx = endptr - line;
	return (construct_result(NULL));
}

t_result	skip_lighting_ratio(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, 0.0, 1.0));
}

t_result	skip_fov(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, DBL_EPSILON, 180 - DBL_EPSILON));
}

t_result	skip_diameter(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, DBL_EPSILON, INFINITY));
}
