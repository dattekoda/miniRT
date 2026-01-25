/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:31:56 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:32:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "vec.h"
#include "result.h"
#include <math.h>
#include <stddef.h>

t_result	skip_vec(const char *line, size_t *line_idx, t_vec3type vectype);

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
