/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_point_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:21:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include "libft.h"
#include "line_reader.h"
#include <unistd.h>

static void	put_err_line(char *line);

void	err_point_out(t_line_reader *line_reader)
{
	size_t	i;

	i = 0;
	put_err_line(line_reader->line);
	while (i < line_reader->idx)
	{
		if (line_reader->line[i++] == '\t')
			ft_putchar_fd('\t', STDERR_FILENO);
		else
			ft_putchar_fd(' ', STDERR_FILENO);
	}
	ft_putendl_fd(GREEN"^"RESET, STDERR_FILENO);
}

static void	put_err_line(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
	{
		ft_putstr_fd(line, STDERR_FILENO);
		return ;
	}
	ft_putendl_fd(line, STDERR_FILENO);
}
