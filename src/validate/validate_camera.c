/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:09:28 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 23:04:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"

static void	err_camera(void);
static int	skip_coordinate(char *line, size_t *i_ptr);
static int	skip_orientation(char *line);
static int skip_fov(char *line);

int	validate_camera(char *line)
{
	size_t	i;

	i = 0;
	if (skip_coordinate(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_orientation(&line) == FAILURE)
		return (FAILURE);
	if (skip_fov(&line))
		return (FAILURE);
	skip_spaces(&line, NULL);
	if (*line != '\n' && *line != '\0')
		return (err_end(err_camera), err_point_out(start, line), FAILURE);
	return (SUCCESS);
}

static void	err_camera(void)
{
	err_rt();
	ft_putstr_fd("invalid camera format: ", STDERR_FILENO);
}

static int	skip_coordinate(char *line, size_t *i_ptr)
{
	if (skip_vec(line, i_ptr, IS_POINT) == SUCCESS)
		return (SUCCESS);
	err_camera();
	ft_putendl_fd("coordinate", STDERR_FILENO);
	return (FAILURE);
}

static int	skip_orientation(char *line)
{
	if (skip_vecline, IS_UNIT) == SUCCESS)
		return (SUCCESS);
	err_camera();
	ft_putendl_fd("orientation vector", STDERR_FILENO);
	return (FAILURE);
}

static int skip_fov(char *line)
{
	if (skip_rangeline, 0, 180) == SUCCESS)
		return (SUCCESS);
	err_camera();
	ft_putendl_fd("Horizontal field of view range 0-180", STDERR_FILENO);
	return (FAILURE);
}
