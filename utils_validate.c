/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:55:04 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 14:06:32 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	skip_spaces(char **line)
{
	if (**line != ' ' && **line != '\t')
		return (MINIRT_FAILURE);
	while (**line == ' ' || **line == '\t')
		(*line)++;
	return (MINIRT_SUCCESS);
}

int	skip_digit(char **line)
{
	if (!ft_isdigit(**line))
		return (MINIRT_FAILURE);
	while (ft_isdigit(**line))
		(*line)++;
	return (MINIRT_SUCCESS);
}

int	validate_ambient(char *line)
{
	double	lighting_ratio;
	int		tmp;
	size_t	i;

	line++;
	if (skip_spaces(&line))
		return (MINIRT_FAILURE);
	lighting_ratio = strtof(line, &line);
	if (lighting_ratio < 0 || 1 < lighting_ratio)
		return (MINIRT_FAILURE);
	if (skip_spaces(&line))
		return (MINIRT_FAILURE);
	i = 0;
	while (i++ < 3)
	{
		tmp = ft_atoi(line);
		if (skip_digit(&line))
			return (MINIRT_FAILURE);
		if (i != 3 && *(line++) != ',')
			return (MINIRT_FAILURE);
	}
	return (!(*line == '\n'));
}

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
