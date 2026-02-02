/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:31:56 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:28:12 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "vec.h"
#include "line_reader.h"
#include "result.h"
#include <math.h>
#include <stddef.h>

t_result	skip_vec(t_line_reader *line_reader, t_vec3type vectype);

t_result	skip_point(t_line_reader *line_reader)
{
	return (skip_vec(line_reader, IS_POINT));
}

t_result	skip_unit(t_line_reader *line_reader)
{
	return (skip_vec(line_reader, IS_UNIT));
}

t_result	skip_color(t_line_reader *line_reader)
{
	return (skip_vec(line_reader, IS_COLOR));
}
