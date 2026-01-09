/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:19:15 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 21:30:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"

int	validate_ambient(char *line)
{
	const t_skip			ambient_skips[] = {
		skip_spaces,
		skip_lighting_ratio,
		skip_spaces,
		skip_color,
		skip_until_end,
		NULL
	};
	const t_element_info	ambient_info = {
		.identifier_len = 1,
		.format = "A [lighting ratio(0-1)] [R,G,B(0-255)]",
		.skip_arr = ambient_skips
	};

	return (validate_element(line, ambient_info));
}
