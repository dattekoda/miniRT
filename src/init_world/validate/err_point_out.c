/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_point_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 00:59:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include "libft.h"
#include <unistd.h>

void	err_point_out(char *line, size_t err_idx)
{
	size_t	i;

	i = 0;
	ft_putendl_fd(line, STDERR_FILENO);
	while (i < err_idx)
	{
		if (line[i++] == '\t')
			ft_putchar_fd('\t', STDERR_FILENO);
		else
			ft_putchar_fd(' ', STDERR_FILENO);
	}
	ft_putendl_fd(GREEN"^"RESET, STDERR_FILENO);
}
