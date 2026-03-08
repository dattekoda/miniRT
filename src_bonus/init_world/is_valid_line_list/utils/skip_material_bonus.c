/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_material_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:16:14 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils_bonus.h"
#include "libft.h"
#include "result_bonus.h"
#include "rt_define_bonus.h"
#include "validate_utils_bonus.h"
#include <stddef.h>

t_result	skip_material(const char *line, size_t *line_idx)
{
	t_result	result;
	char		*str;

	result = skip_spaces(line, line_idx);
	if (result.state == FAILURE)
		return (result);
	result = token_to_str(line, line_idx, &str);
	if (result.state == FAILURE)
		return (result);
	if (str_to_material_idx(str) == INVALID_MATERIAL_IDX)
	{
		(*line_idx)--;
		return (construct_result(
				"material specifier should be: lambertian metal dielectric"));
	}
	return (construct_result(NULL));
}
