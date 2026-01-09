/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:43:14 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 18:03:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "libft.h"
#include <stddef.h>
#include <unistd.h>

t_result	construct_result(char *_err_msg)
{
	t_result	result;

	ft_bzero(&result, sizeof(t_result));
	if (_err_msg == NULL)
	{
		result.state = OK;
		result.value.ok = 0;
		return (result);
	}
	result.state = ERROR;
	result.value.err_msg = _err_msg;
	return (result);
}

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
