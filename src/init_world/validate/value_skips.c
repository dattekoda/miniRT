/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_skips.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:30:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 13:01:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <float.h>
#include <math.h>
#include <stddef.h>

t_result	skip_range(const char *line, size_t *line_idx, \
double min, double max);

t_result	skip_lighting_ratio(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, 0.0, 1.0));
}

t_result	skip_angle(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, FLT_EPSILON, 180.0 - FLT_EPSILON));
}

t_result	skip_sharp_angle(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, FLT_EPSILON, 90.0 - FLT_EPSILON));
}

t_result	skip_length(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, DBL_EPSILON, INFINITY));
}
