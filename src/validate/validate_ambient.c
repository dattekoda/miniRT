/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:01:13 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 19:03:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"

static void	err_ambient(void);
static void	err_lighting_ratio(void);
static void	err_end(void);

int	validate_ambient(char *line)
{
	if (skip_spaces(&line))
		return (err_spaces(err_ambient), FAILURE);
	if (skip_range(&line, 0, 1) == FAILURE)
		return (err_range(err_lighting_ratio, 0, 1), FAILURE);
	if (skip_spaces(&line) == FAILURE)
		return (err_spaces(err_ambient), FAILURE);
	if (skip_vec(&line, IS_COLOR) == FAILURE)
		return (err_vec(err_ambient, IS_COLOR), FAILURE);
	skip_spaces(&line);
	if (*line != '\n' && *line != '\0')
		return (err_end(), FAILURE);
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

static void	err_end(void)
{
	err_ambient();
	ft_putendl_fd("incorrect line ending", STDERR_FILENO);
}
