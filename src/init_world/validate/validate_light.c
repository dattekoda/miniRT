/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:29:28 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 21:17:23 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"

int	validate_light(char *line)
{
	const t_skip			light_skips[] = {
		skip_spaces,
		skip_point,
		skip_spaces,
		skip_lighting_ratio,
		skip_spaces,
		skip_color,
		skip_until_end,
		NULL
	};
	const t_element_info	light_info = {
		.identifier_len = 1,
		.format = \
"L [coordinate](x,y,z) [light brightness ratio](0-1) [R,G,B](0-255)",
		.skip_arr = light_skips
	};

	return (validate_element(line, light_info));
}
