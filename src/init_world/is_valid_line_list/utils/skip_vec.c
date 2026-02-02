/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:25:40 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "validate_utils.h"
#include "init_world_utils.h"
#include "libft.h"
#include "line_reader.h"
#include <math.h>

static int	validate_color(t_color d3);
static int	validate_unit_vec3(t_color d3);

t_result	skip_vec(t_line_reader *line_reader, t_vec3type vectype)
{
	t_result	result;
	t_vec3		d3;

	result = skip_spaces(line_reader);
	if (result.state == FAILURE)
		return (result);
	ft_bzero(&d3, sizeof(t_vec3));
	result = token_to_vec(line_reader, &d3);
	if (result.state == FAILURE)
		return (result);
	if (vectype == IS_COLOR && validate_color(d3) == FAILURE)
	{
		(line_reader->idx)--;
		return (construct_result("invalid color range"));
	}
	if (vectype == IS_UNIT && validate_unit_vec3(d3) == FAILURE)
	{
		(line_reader->idx)--;
		return (construct_result("not normalized vector"));
	}
	return (construct_result(NULL));
}

static int	validate_color(t_color d3)
{
	size_t	d_idx;

	d_idx = 0;
	while (d_idx < 3)
	{
		if (d3.e[d_idx] < 0.0 || 255.0 < d3.e[d_idx])
			return (FAILURE);
		d_idx++;
	}
	return (SUCCESS);
}

static int	validate_unit_vec3(t_color d3)
{
	double	squred_sum;

	squred_sum = pow(d3.e[0], 2) + pow(d3.e[1], 2) + pow(d3.e[2], 2);
	if (0.01 <= fabs(squred_sum - 1))
		return (FAILURE);
	return (SUCCESS);
}
