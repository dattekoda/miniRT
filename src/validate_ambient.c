/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:40:27 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/29 18:19:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "miniRT_define.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

//necessary to implement strtod
static void	err_ambient(void)
{
	static char	*msg = \
"\x1b[31m""Set ambient information correctly.\n" \
"\x1b[0m""A [lighting ratio] ""\x1b[31m""R"",""\x1b[32m""G"",""\x1b[34m""B";

	ft_putendl_fd(msg, STDERR_FILENO);
}

int	validate_ambient(char *line_ptr)
{
	double	lighting_ratio;
	int		tmp;
	size_t	i;

	line_ptr++;
	if (skip_spaces(&line_ptr))
		return (err_ambient(), EXIT_FAILURE);
	lighting_ratio = strtof(line_ptr, &line_ptr);
	if (lighting_ratio < 0 || 1 < lighting_ratio)
		return (err_ambient(), EXIT_FAILURE);
	if (skip_spaces(&line_ptr))
		return (err_ambient(), EXIT_FAILURE);
	i = 0;
	while (i++ < 3)
	{
		tmp = ft_atoi(line_ptr);
		if ((tmp < 0 || 255 < tmp) || skip_digit(&line_ptr))
			return (err_ambient(), EXIT_FAILURE);
		if (i != 3 && *(line_ptr++) != ',')
			return (err_ambient(), EXIT_FAILURE);
	}
	if (*line_ptr == '\n')
		return (EXIT_SUCCESS);
	return (err_ambient(), EXIT_FAILURE);
}
