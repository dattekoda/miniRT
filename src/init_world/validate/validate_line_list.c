/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:28:34 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/08 16:55:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "define_rt.h"
#include "util_rt.h"
#include "libft.h"
#include <unistd.h>

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
	size_t	i;

	i = 0;
	while (g_elem_table[i].type != NOTHING)
	{
		if (ft_strncmp(line, g_elem_table[i].str, g_elem_table[i].str_len) == 0)
			return (g_elem_table[i].validate(line));
		i++;
	}
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
