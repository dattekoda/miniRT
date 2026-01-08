/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:24:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/08 17:00:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"
#include <unistd.h>

static int	skip_coordinate(char *line, size_t *i_ptr);
static int	skip_brightness_ratio(char *line, size_t *i_ptr);
static int	skip_color(char *line, size_t *i_ptr);

int	validate_light(char *line)
{
	size_t	i;

	i = 0;
	if (skip_coordinate(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_brightness_ratio(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_color() == FAILURE)
		return (FAILURE);
	
}

static int	skip_coordinate(char *line, size_t *i_ptr, t_element_info eelm_type)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_vec(line, i_ptr, IS_POINT) == FAILURE)
	{
		err_light();
		ft_putendl_fd("invalid light coordinate", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_brightness_ratio(char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_range(line, i_ptr, 0, 1) == FAILURE)
	{
		err_light();
		ft_putendl_fd("invalid  light brightness ratio", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_color(char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_vec(line, i_ptr, IS_COLOR) == FAILURE)
	{
		err_light();
		ft_putendl_fd("R,G,B[0,255] colors invalid format", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}
