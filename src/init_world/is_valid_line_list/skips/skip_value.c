/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:30:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:27:26 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_reader.h"
#include "result.h"
#include <float.h>
#include <math.h>
#include <stddef.h>

t_result	skip_range(t_line_reader *line_reader,
						double min, double max);

t_result	skip_lighting_ratio(t_line_reader *line_reader)
{
	return (skip_range(line_reader, 0.0, 1.0));
}

t_result	skip_angle(t_line_reader *line_reader)
{
	return (skip_range(line_reader, FLT_EPSILON, 180.0 - FLT_EPSILON));
}

t_result	skip_sharp_angle(t_line_reader *line_reader)
{
	return (skip_range(line_reader, FLT_EPSILON, 90.0 - FLT_EPSILON));
}

t_result	skip_length(t_line_reader *line_reader)
{
	return (skip_range(line_reader, DBL_EPSILON, INFINITY));
}
