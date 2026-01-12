/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/11 16:53:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "libft.h"
#include <math.h>

static int	validate_color(double d3[3]);
static int	validate_unit_vec3(double d3[3]);

t_result	skip_vec(const char *line, size_t *line_idx, t_vec3type vectype)
{
	t_result	result;
	double		d3[3];

	result = skip_spaces(line, line_idx);
	if (result.state == FAILURE)
		return (result);
	ft_bzero(d3, sizeof(double) * 3);
	result = line_to_vec(line, line_idx, d3);
	if (result.state == FAILURE)
		return (result);
	if (vectype == IS_COLOR && validate_color(d3) == FAILURE)
	{
		(*line_idx)--;
		return (construct_result("invalid color range"));
	}
	if (vectype == IS_UNIT && validate_unit_vec3(d3) == FAILURE)
	{
		(*line_idx)--;
		return (construct_result("not normalized vector"));
	}
	return (construct_result(NULL));
}

static int	validate_color(double d3[3])
{
	size_t	d_idx;

	d_idx = 0;
	while (d_idx < 3)
	{
		if (d3[d_idx] < 0.0 || 255.0 < d3[d_idx])
			return (FAILURE);
		d_idx++;
	}
	return (SUCCESS);
}

static int	validate_unit_vec3(double d3[3])
{
	double	squred_sum;

	squred_sum = pow(d3[0], 2) + pow(d3[1], 2) + pow(d3[2], 2);
	if (0.01 <= fabs(squred_sum - 1))
		return (FAILURE);
	return (SUCCESS);
}
