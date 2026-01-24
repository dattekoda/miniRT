/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:46:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/23 16:48:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include <unistd.h>
#include <stdbool.h>

bool	is_valid_option(char **options)
{
	char	*option;
	size_t	i;
	char	tmp;

	i = 0;
	while (options[i])
	{
		option = options[i];
		if (option[0] != '-')
			return (err_rt("option needs to start with '-'"), false);
		if (!is_valid_short_option(option) || !is_valid_long_option(option))
			return (false);
	}
	return (true);
}

static bool	is_valid_short_option(char *option)
{
	size_t	i1;
	size_t	i2;

	i1 = 1;
	while (option[i1])
	{
		i2 = 0;
		while (g_option_table[i2])
		{
			if (g_option_table[i2++]->str[0] == option[i1])
				break ;
		}
		if ((g_option_table[i2]) == NULL)
			return (err_set_short_option(option[i1]), false);
		i1++;
	}
	return (true);
}

static bool	is_valid_long_option(char *option)
{
	size_t	i;

	i = 0;
	while (g_option_table[i])
	{
		if (ft_strncmp(g_option_table[i]->str, option + 2, ft_strlen(g_option_table[i])))
			break ;
	}
	if ((g_option_table[i]) == NULL)
		return (false);
	return (true);
}

static void	err_set_short_option(char c)
{
	err_rt(NULL);
	ft_putstr_fd("invalid option -- '", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

static void	err_set_long_option(char *s)
{
	err_rt(NULL);
	ft_putstr_fd("invalid option -- '", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}
