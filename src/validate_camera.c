/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:15:47 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/28 15:29:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "validate_utils.h"
#include <stdlib.h>

// You need to imprement new function
// which return true if two doubles are almost equal
// but in the first place, libft doesn't
// have fabs nor strtof so...
int	validate_camera(char *line_ptr)
{
	double	d_tmp;
	size_t	i;

	line_ptr++;
	i = 0;
	while (i++ < 3)
	{
		d_tmp = strtof(line_ptr, &line_ptr);
		if (i != 3 && *(line_ptr++) != ',')
			return (MINIRT_FAILURE);
	}
	if (skip_spaces(&line_ptr))
		return (MINIRT_FAILURE);
}
