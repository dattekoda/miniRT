/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:26:35 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 16:33:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"

static int	skip_coordinate(char *line, size_t *i_ptr);
static int	skip_diameter(char *line, size_t *i_ptr);
static int	skip_color(char *line, size_t *i_ptr);

int	validate_sphere(char *line)
{
	size_t	i;

	i = 1;
	if (skip_coordinate(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_diameter(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_orientation(line, &i) == FAILURE)
		return (FAILURE);
	skip_spaces(line, NULL);
	if (line[i] != '\n' && line[i] != '\0')
	{
		err_sphere();
		err_end();
		err_point_out(line, i);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_coordinate(char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_vec(line, i_ptr, IS_POINT) == FAILURE)
	{
		err_sphere();
		ft_putendl_fd("invalid coordinate", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_light_ratio(char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_range(line, i_ptr, 0, ) == FAILURE)
	{
		err_sphere();
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}
