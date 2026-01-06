/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:08:58 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 20:47:48 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "validate_define.h"
#include "libft.h"

void	err_point_out(char *start, char *err_ptr)
{
	size_t	i;
	size_t	point;
	size_t	tab_count;

	i = 0;
	tab_count = 0;
	point = err_ptr - start;
	ft_putstr_fd(start, STDERR_FILENO);
	while (i++ < point)
	{
		if (start[i] == '\t')
			tab_count++;
	}
	point -= tab_count;
	i = 0;
	while (i++ < point)
		ft_putchar_fd(' ', STDERR_FILENO);
	i = 0;
	while (i++ < tab_count)
		ft_putchar_fd('\t', STDERR_FILENO);
	ft_putendl_fd(GREEN"^"RESET, STDERR_FILENO);
}

void	err_spaces(void (*f)(void))
{
	if (f)
		f();
	ft_putendl_fd("need spaces", STDERR_FILENO);
}

void	err_end(void (*f)(void))
{
	f();
	ft_putendl_fd("incorrect line ending", STDERR_FILENO);
}
