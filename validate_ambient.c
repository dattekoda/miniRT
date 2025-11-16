/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:40:27 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 14:41:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "miniRT_define.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
//strtofを実装する必要あり。

static void	err_ambient()
{
	static char	*msg = \
	"\x1b[31m""Set ambient information correctly.\n" \
	"\x1b[0m""A [lighting ratio] ""\x1b[31m""R"",""\x1b[32m""G"",""\x1b[34m""B";

	ft_putendl_fd(msg, STDERR_FILENO);
}

int	validate_ambient(char *line)
{
	double	lighting_ratio;
	int		tmp;
	size_t	i;

	line++;
	if (skip_spaces(&line))
		return (err_ambient(), MINIRT_FAILURE);
	lighting_ratio = strtof(line, &line);
	if (lighting_ratio < 0 || 1 < lighting_ratio)
		return (err_ambient(), MINIRT_FAILURE);
	if (skip_spaces(&line))
		return (err_ambient(), MINIRT_FAILURE);
	i = 0;
	while (i++ < 3)
	{
		tmp = ft_atoi(line);
		if ((tmp < 0 || 255 < tmp) || skip_digit(&line))
			return (err_ambient(), MINIRT_FAILURE);
		if (i != 3 && *(line++) != ',')
			return (err_ambient(), MINIRT_FAILURE);
	}
	if (*line == '\n')
		return (MINIRT_SUCCESS);
	return (err_ambient(), MINIRT_FAILURE);
}
