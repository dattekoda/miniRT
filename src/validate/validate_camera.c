/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:28:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/07 18:30:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"

static void	err_camera(void);
static int	skip_coordinate(const char *line, size_t *i_ptr);
static int	skip_orientation(const char *line, size_t *i_ptr);
static int	skip_fov(const char *line, size_t *i_ptr);

int	validate_camera(const char *line)
{
	size_t	i;

	i = 0;
	if (skip_coordinate(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_orientation(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_fov(line, &i))
		return (FAILURE);
	skip_spaces_with_err_msg(&line, NULL);
	if (*line != '\n' && *line != '\0')
	{
		err_camera();
		err_end();
		err_point_out(line, i);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	err_camera(void)
{
	err_rt();
	ft_putstr_fd("invalid camera format: ", STDERR_FILENO);
}

static int	skip_coordinate(const char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_vec(line, i_ptr, IS_POINT) == SUCCESS)
	{
		err_camera();
		ft_putendl_fd("invalid camera coordinate", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_orientation(const char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_vec(line, i_ptr, IS_UNIT) == FAILURE)
	{
		err_camera();
		ft_putendl_fd("invalid orientation vector", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_fov(const char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_range(line, i_ptr, 0, 180) == SUCCESS)
	{
		err_camera();
		ft_putendl_fd("invalid fov", STDERR_FILENO);
		return (FAILURE);
	}
	return (SUCCESS);
}
