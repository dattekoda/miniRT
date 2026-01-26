/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:46:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 08:35:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdbool.h>

static bool	is_valid_short_option(char *option);
static bool	is_valid_long_option(char *option);
static void	err_set_short_option(char c);
static void	err_set_long_option(char *str);

bool	is_valid_option(char **options)
{
	char	*option;
	size_t	i;

	i = 0;
	while (options[i])
	{
		option = options[i];
		if (option[0] != '-')
			return (err_rt("option needs to start with '-'"), false);
		if (option[1] == '-')
		{
			if (!is_valid_long_option(option))
				return (false);
		}
		else if (!is_valid_short_option(option))
			return (false);
		i++;
	}
	return (true);
}

/*
@brief -a, -m
*/
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
			if (g_option_table[i2]->str[0] == option[i1])
				break ;
			i2++;
		}
		if ((g_option_table[i2]) == NULL)
			return (err_set_short_option(option[i1]), false);
		i1++;
	}
	return (true);
}

/*
@brief --artificial 
*/
static bool	is_valid_long_option(char *option)
{
	size_t	i;

	i = 0;
	while (g_option_table[i])
	{
		if (!ft_strcmp(g_option_table[i]->str, option + 2))
			break ;
		i++;
	}
	if ((g_option_table[i]) == NULL)
	{
		err_set_long_option(option);
		return (false);
	}
	return (true);
}

static void	err_set_short_option(char c)
{
	err_rt(NULL);
	ft_putstr_fd("invalid option -- '", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

static void	err_set_long_option(char *str)
{
	err_rt(NULL);
	ft_putstr_fd("invalid option -- '", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}
