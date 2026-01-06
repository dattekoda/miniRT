/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:01:13 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 22:58:56 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"

static void	err_ambient(void);
static void	err_lighting_ratio(void);

int	validate_ambient(char *line)
{
	size_t	i;

	i = 0;
	if (skip_spaces(line, &i, err_ambient))
		return (err_point_out(start - 1, line), FAILURE);
	if (skip_range(&line, 0, 1, err_lighting_ratio) == FAILURE)
		return (err_point_out(start - 1, line), FAILURE);
	if (skip_spaces(&line, err_ambient) == FAILURE)
		return (err_point_out(start - 1, line), FAILURE);
	if (skip_vec(&line, IS_COLOR, err_ambient) == FAILURE)
		return (err_point_out(start - 1, line), FAILURE);
	skip_spaces(&line, NULL);
	if (*line != '\n' && *line != '\0')
		return (err_end(err_ambient), err_point_out(start, line), FAILURE);
	return (SUCCESS);
}

static void	err_ambient(void)
{
	err_rt();
	ft_putstr_fd("invalid ambient format: ", STDERR_FILENO);
}

static void	err_lighting_ratio(void)
{
	err_ambient();
	ft_putstr_fd("lighting ratio: ", STDERR_FILENO);
}
