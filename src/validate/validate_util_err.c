/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:08:58 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 11:58:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "validate_define.h"
#include "libft.h"
#include <unistd.h>

void	err_point_out(char *line, size_t err_idx)
{
	size_t	i;
	size_t	tab_count;

	i = 0;
	tab_count = 0;
	ft_putendl_fd(line, STDERR_FILENO);
	while (i++ < err_idx)
	{
		if (line[i] == '\t')
			tab_count++;
	}
	err_idx -= tab_count;
	i = 0;
	while (i++ < err_idx)
		ft_putchar_fd(' ', STDERR_FILENO);
	i = 0;
	while (i++ < tab_count)
		ft_putchar_fd('\t', STDERR_FILENO);
	ft_putendl_fd(GREEN"^"RESET, STDERR_FILENO);
}

void	err_spaces(void)
{
	ft_putendl_fd("need spaces", STDERR_FILENO);
}

void	err_end(void)
{
	ft_putendl_fd("incorrect line ending", STDERR_FILENO);
}
