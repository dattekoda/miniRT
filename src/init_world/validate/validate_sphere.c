/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:42:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 21:30:15 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "math.h"
#include "float.h"

static t_result	skip_diameter(const char *line, size_t *line_idx);

int	validate_sphere(char *line)
{
	const t_skip			sphere_skips[] = {
		skip_spaces,
		skip_point,
		skip_spaces,
		skip_diameter,
		skip_spaces,
		skip_color,
		skip_until_end,
		NULL
	};
	const t_element_info	sphere_info = {
		.identifier_len = 2,
		.format = "sp [coordinate](x,y,z) [diameter](>0) [R,G,B](0-255)",
		.skip_arr = sphere_skips
	};

	return (validate_element(line, sphere_info));
}

static t_result	skip_diameter(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, DBL_EPSILON, INFINITY));
}
