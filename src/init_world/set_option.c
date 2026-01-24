/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:36:53 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 18:11:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_define.h"
#include "rt_utils.h"
#include "libft.h"
#include <unistd.h>

/*
@brief set option like -p
*/
int	set_option(const char *options[])
{
	int					bit_flag;
	size_t				i;
	char				*tmp;

	bit_flag = 0;
	i = 1;
	while (options[i])
	{
		if (options[i] + 2 == '-')
			bit_flag |= set_long_option(options[i] + 2);
		else
			bit_flag |= set_short_option(options[i] + 1);
		i++;
	}
	return (bit_flag);
}

static int	set_long_option(const char *option)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(option);
	i = 0;
	while (g_option_table[i])
	{
		if (!ft_strncmp(g_option_table[i]->str, option, len))
			return (g_option_table[i]->flag);
	}
	return (0);
}

static int	set_short_option(const char *option)
{
	int		bit_flag;
	size_t	i;

	bit_flag = 0;
	i = 0;
	while (*option)
	{
		while (g_option_table[i])
		{
			if (g_option_table[i]->str[0] == *option)
				bit_flag |= g_option_table[i]->flag;
		}
		option++;
	}
	return (bit_flag);
}
