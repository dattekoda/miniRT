/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:36:53 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/26 08:41:11 by ikawamuk         ###   ########.fr       */
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
	i = 0;
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

	i = 0;
	while (g_option_table[i])
	{
		if (!ft_strcmp(g_option_table[i]->str, option))
			return (g_option_table[i]->flag);
		i++;
	}
	return (0);
}

static int	set_short_option(char *option)
{
	int		bit_flag;
	size_t	i;

	bit_flag = 0;
	while (*option)
	{
		i = 0;
		while (g_option_table[i])
		{
			if (g_option_table[i]->str[0] == *option)
				bit_flag |= g_option_table[i]->flag;
			i++;
		}
		option++;
	}
	return (bit_flag);
}
