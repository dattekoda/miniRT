/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:36:53 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/25 02:41:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "libft.h"

static int	set_long_option(char *option);
static int	set_short_option(char *option);

/*
@brief set option like -p
*/
int	set_option(char *options[])
{
	size_t	i;
	int		bit_flag;

	bit_flag = 0;
	i = 1;
	while (options[i])
	{
		if (options[i][1] == '-')
			bit_flag |= set_long_option(options[i] + 2);
		else
			bit_flag |= set_short_option(options[i] + 1);
		i++;
	}
	return (bit_flag);
}

static int	set_long_option(char *option)
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

static int	set_short_option(char *option)
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
