/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:26:48 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 21:18:57 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"

static t_result	skip_fov(const char *line, size_t *line_idx);

int	validate_camera(char *line)
{
	const t_skip			camera_skips[] = {
		skip_spaces,
		skip_point,
		skip_spaces,
		skip_unit,
		skip_spaces,
		skip_fov,
		skip_until_end,
		NULL
	};
	const t_element_info	camera_info = {
		.identifier_len = 1,
		.format = \
"C [coordinate](x,y,z) [normalized orient vector](a,b,c) [fov](0-180)",
		.skip_arr = camera_skips
	};

	return (validate_element(line, camera_info));
}

static t_result	skip_fov(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, 0, 180));
}
