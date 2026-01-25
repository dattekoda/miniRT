/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_point_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 16:46:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include "libft.h"
#include <unistd.h>

static void	put_err_line(char *line);

void	err_point_out(char *line, size_t err_idx)
{
	size_t	i;

	i = 0;
	put_err_line(line);
	while (i < err_idx)
	{
		if (line[i++] == '\t')
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
