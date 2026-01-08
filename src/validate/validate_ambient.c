/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:01:13 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 11:57:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"
#include <unistd.h>

static void	err_ambient(void);
static int	skip_ambient_light_ratio(char *line, size_t *i_ptr);
static int	skip_ambient_color(char *line, size_t *i_ptr);

int	validate_ambient(char *line)
{
	size_t	i;

	i = 1;
	if (skip_ambient_light_ratio(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_ambient_color(line, &i) == FAILURE)
		return (FAILURE);
	skip_spaces_with_err_msg(line, &i);
	if (line[i] != '\n' && line[i] != '\0')
	{
		err_ambient();
		err_end();
		err_point_out(line, i);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_ambient_light_ratio(char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
	{
		err_ambient();
		ft_putendl_fd("need space", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	if (skip_range(line, i_ptr, 0, 1) == FAILURE)
	{
		err_ambient();
		ft_putendl_fd("invalid ambient lighting ratio", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_ambient_color(char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_vec(line, i_ptr, IS_COLOR) == FAILURE)
	{
		err_ambient();
		ft_putendl_fd("R,G,B[0,255] colors invalid format", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	err_ambient(void)
{
	err_rt();
	ft_putstr_fd("invalid ambient format: ", STDERR_FILENO);
	return ;
}
