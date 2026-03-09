/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_vector_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:31:56 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:31:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define_bonus.h"
#include "vec_bonus.h"
#include "result_bonus.h"
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
