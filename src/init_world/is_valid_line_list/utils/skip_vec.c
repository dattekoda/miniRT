/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 23:25:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "validate_utils.h"
#include "init_world_utils.h"
#include "vec_utils.h"
#include "libft.h"
#include <math.h>

static int	validate_color(t_color color);
static int	validate_unit_vec3(t_vec3 v);

t_result	skip_vec(const char *line, size_t *line_idx, t_vec3type vectype)
{
	t_result	result;
	t_vec3		vec3;

	result = skip_spaces(line, line_idx);
	if (result.state == FAILURE)
		return (result);
	ft_bzero(&vec3, sizeof(t_vec3));
	result = token_to_vec(line, line_idx, &vec3);
	if (result.state == FAILURE)
		return (result);
	if (vectype == IS_COLOR && validate_color(vec3) == FAILURE)
	{
		(*line_idx)--;
		return (construct_result("invalid color range"));
	}
	if (vectype == IS_UNIT && validate_unit_vec3(vec3) == FAILURE)
	{
		(*line_idx)--;
		return (construct_result("not normalized vector"));
	}
	return (construct_success_result());
}

static int	validate_color(t_color color)
{
	t_rgb	rgb_idx;

	rgb_idx = E_R;
	while (rgb_idx < E_B)
	{
		if (color.e[rgb_idx] < 0.0 || 255.0 < color.e[rgb_idx])
			return (FAILURE);
		rgb_idx++;
	}
	return (SUCCESS);
}

static int	validate_unit_vec3(t_vec3 vec3)
{
	double	squred_sum;

	squred_sum = length_squared_vec3(vec3);
	if (fabs(squred_sum - 1) > 0.01)
		return (FAILURE);
	return (SUCCESS);
}
