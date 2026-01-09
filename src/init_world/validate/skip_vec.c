/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 01:53:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "libft.h"
#include <math.h>

static t_result	skip_vec(const char *line, size_t *line_idx, t_vectype vectype);
static int		validate_unit_vec(double d3[3]);

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
		if (result.state == FAILURE)
			return (result);
		if (++d_idx != 3)
		{
			skip_spaces(line, line_idx);
			if (line[*line_idx] != ',')
				return (construct_result("need ','"));
			(*line_idx)++;
		}
	}
	if (vectype == IS_UNIT && validate_unit_vec(d3))
		return ((*line_idx)--, construct_result("not normalized vector"));
	return (construct_result(NULL));
}

static int	validate_unit_vec(double d3[3])
{
	double	squred_sum;

	squred_sum = pow(d3[0], 2) + pow(d3[1], 2) + pow(d3[2], 2);
	return (0.01 <= fabs(squred_sum - 1));
}
