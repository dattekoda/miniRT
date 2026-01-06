/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:09:28 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 19:22:40 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"

static void	err_camera(void);
static void	err_coordinate(void);
static void	err_orientation(void);
static void	err_fov(void);

int	validate_camera(char *line)
{
	if (skip_spaces(&line))
		return (err_spaces(err_camera), FAILURE);
	if (skip_vec(&line, IS_POINT) == FAILURE)
		return (err_vec(err_coordinate, IS_POINT), FAILURE);
	if (skip_spaces(&line) == FAILURE)
		return (err_spaces(err_camera), FAILURE);
	if (skip_vec(&line, IS_UNIT) == FAILURE)
		return (err_vec(err_orientation, IS_UNIT), FAILURE);
	if (skip_spaces(&line) == FAILURE)
		return (err_spaces(err_camera), FAILURE);
	if (skip_range(&line, 0, 180) == FAILURE)
		return (err_range(err_fov, 0, 180), FAILURE);
	skip_spaces(&line);
	if (*line != '\n' && *line != '\0')
		return (err_end(err_camera), FAILURE);
	return (SUCCESS);
}

static void	err_camera(void)
{
	err_rt();
	ft_putstr_fd("invalid camera format: ", STDERR_FILENO);
}

static void	err_coordinate(void)
{
	err_camera();
	ft_putstr_fd("coordinate: ", STDERR_FILENO);
}

static void	err_orientation(void)
{
	err_camera();
	ft_putstr_fd("orientation vector: ", STDERR_FILENO);
}

static void	err_fov(void)
{
	err_camera();
	ft_putstr_fd("Horizontal field of view: ", STDERR_FILENO);
}
