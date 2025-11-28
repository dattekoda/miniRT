/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:55:04 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 14:40:34 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "validate_utils.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	validate_line_ptr(char *line_ptr)
{
	if (*line_ptr == 'A')
		return (validate_ambient(line_ptr));
	if (*line_ptr == 'C')
		return (MINIRT_SUCCESS);
		// return (validate_camera(line_ptr));
	if (*line_ptr == 'L')
		return (MINIRT_SUCCESS);
		// return (validate_light(line_ptr));
	if (!ft_strncmp(line_ptr, "sp", 2))
		return (MINIRT_SUCCESS);
		// return (validate_sphere(line_ptr));
	if (ft_strncmp(line_ptr, "pl", 2))
		return (MINIRT_SUCCESS);
		// return (validate_plane(line_ptr));
	if (ft_strncmp(line_ptr, "cy", 2))
		return (MINIRT_SUCCESS);
		// return (validate_plane(line_ptr));
	return MINIRT_FAILURE;
}

int	validate_content(char *content)
{
	size_t	i;
	char	*line_ptr;

	i = 0;
	line_ptr = content;
	while (line_ptr)
	{
		while (*line_ptr == '\n')
			line_ptr++;
		if (validate_line_ptr(line_ptr))
			return (MINIRT_FAILURE);
		line_ptr = ft_strchr(line_ptr, '\n');
	}
	return (MINIRT_SUCCESS);
}
