/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rt_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:28:34 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/07 18:30:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "define_rt.h"
#include "util_rt.h"
#include "libft.h"

int			validate_ambient(const char *line);
int			validate_camera(const char *line);
int			validate_light(const char *line);
int			validate_plane(const char *line);
int			validate_sphere(const char *line);
int			validate_cylinder(const char *line);
int			validate_cone(const char *line);
int			validate_triangle(const char *line);

static int	distribute_validate(char *line);
static void	err_distribute(char *line);
static void	err_set(char *element);

int	validate_line_list(const t_list *line_list)
{
	int	a_count;
	int	c_count;

	a_count = 0;
	c_count = 0;
	while (line_list)
	{
		if (*(char *)(line_list->content) == 'A')
			a_count++;
		if (*(char *)(line_list->content) == 'C')
			c_count++;
		if (distribute_validate(line_list->content))
			return (FAILURE);
		line_list = line_list->next;
	}
	if (a_count == 1 && c_count == 1)
		return (SUCCESS);
	if (a_count != 1)
		err_set("'ambient'");
	if (c_count != 1)
		err_set("'camera'");
	return (FAILURE);
}

static void	err_set(char *element)
{
	err_rt();
	ft_putstr_fd("Set only one ", STDERR_FILENO);
	ft_putendl_fd(element, STDERR_FILENO);
}

static int	distribute_validate(char *line)
{
	if (*line == 'A')
		return (validate_ambient(line + 1));
	if (*line == 'C')
		return (validate_camera(line + 1));
	// if (*line == 'L')
	// 	return (validate_light(line + 1));
	// if (ft_strncmp(line, "pl", 2) == 0)
	// 	return (validate_plane(line + 2));
	// if (ft_strncmp(line, "sp", 2) == 0)
	// 	return (validate_sphere(line + 2));
	// if (ft_strncmp(line, "cy", 2) == 0)
	// 	return (validate_cylinder(line + 2));
	// if (ft_strncmp(line, "co", 2) == 0)
	// 	return (validate_cone(line + 2));
	// if (ft_strncmp(line, "tr", 2) == 0)
	// 	return (validate_triangle(line + 2));
	return (err_distribute(line), FAILURE);
}

static void	err_distribute(char *line)
{
	err_rt();
	ft_putstr_fd("invalid identifier '", STDERR_FILENO);
	while (line && ft_isspace(*line) == 0)
		ft_putchar_fd(*(line++), STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}
