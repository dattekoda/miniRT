/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:55:04 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/29 19:11:37 by khanadat         ###   ########.fr       */
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
	static const char	*object_identifier[] = {
		"sp", "pl", "cy", NULL
	};
	size_t				i;

	if (*line_ptr == 'A')
		return (validate_ambient(line_ptr));
	if (*line_ptr == 'C')
		return (EXIT_SUCCESS);
	if (*line_ptr == 'L')
		return (EXIT_SUCCESS);
	i = 0;
	while (object_identifier[i])
	{
		if (!ft_strncmp(line_ptr, object_identifier[i++], 2))
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
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
			return (EXIT_FAILURE);
		line_ptr = ft_strchr(line_ptr, '\n');
	}
	return (EXIT_SUCCESS);
}
