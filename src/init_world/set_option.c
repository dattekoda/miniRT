/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:36:53 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 01:09:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"
#include "libft.h"
#include <unistd.h>

static void	err_invalid_option(void);
static void	err_set_option(int c);

/*
@brief set option like -p
*/
int	set_option(const char *options)
{
	static const char	table[] = "p";
	int					bit_flag;
	size_t				i;
	char				*tmp;

	if (!options)
		return (0);
	if (options[0] != '-')
		return (err_invalid_option(), 0);
	bit_flag = 0;
	i = 1;
	while (options[i])
	{
		tmp = ft_strchr(table, options[i++]);
		if (tmp == NULL)
		{
			err_set_option(options[i - 1]);
			return (0);
		}
		bit_flag |= (1 << (tmp - table));
	}
	return (bit_flag);
}

static void	err_invalid_option(void)
{
	err_rt();
	ft_putendl_fd("option needs to start with '-'", STDERR_FILENO);
}

static void	err_set_option(int c)
{
	err_rt();
	ft_putstr_fd("invalid option -- '", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}
