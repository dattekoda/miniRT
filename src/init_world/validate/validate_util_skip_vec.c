/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util_skip_vec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:48:28 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 21:16:01 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "libft.h"
#include <stddef.h>
#include <math.h>

static t_result	skip_value(const char *line, size_t *line_idx, \
t_vectype vectype, double *d);
static t_result	skip_vec(const char *line, size_t *line_idx, \
t_vectype vectype);

t_result	skip_point(const char *line, size_t *line_idx)
{
	return (skip_vec(line, line_idx, IS_POINT));
}

t_result	skip_unit(const char *line, size_t *line_idx)
{
	return (skip_vec(line, line_idx, IS_UNIT));
}

t_result	skip_color(const char *line, size_t *line_idx)
{
	return (skip_vec(line, line_idx, IS_COLOR));
}

static t_result	skip_value(const char *line, size_t *line_idx, \
t_vectype vectype, double *d)
{
	char	*endptr;

	*d = ft_strtod(line + *line_idx, &endptr);
	if (endptr == line + *line_idx)
		return (construct_result("need valid vector value"));
	*line_idx = endptr - line - 1;
	if (isnan(*d) || isinf(*d))
		return (construct_result("invalid vector value"));
	if (vectype == IS_COLOR && (*d < 0.0 || 255.0 < *d))
		return (construct_result("invalid color range"));
	*line_idx = (size_t)(endptr - line);
	return (construct_result(NULL));
}

static t_result	skip_vec(const char *line, size_t *line_idx, t_vectype vectype)
{
	t_result	result;
	double		d3[3];
	size_t		d_idx;

	ft_bzero(d3, sizeof(double) * 3);
	d_idx = 0;
	while (d_idx < 3)
	{
		result = skip_value(line, line_idx, vectype, d3 + d_idx);
		if (result.state == ERROR)
			return (result);
		if (++d_idx != 3)
			if (line[(*line_idx)++] != ',')
				return ((*line_idx)--, construct_result("need ','"));
	}
	if (vectype == IS_UNIT && 0.01 \
<= fabs(pow(d3[0], 2) + pow(d3[1], 2) + pow(d3[2], 2) - 1))
		return ((*line_idx)--, construct_result("not normalized vector"));
	return (construct_result(NULL));
}
