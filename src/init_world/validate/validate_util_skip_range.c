/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util_skip_range.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:05:34 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 21:16:15 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "libft.h"
#include <stddef.h>
#include <math.h>

t_result	skip_range(const char *line, size_t *line_idx, \
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
