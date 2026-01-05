/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:26:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/05 23:04:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "util_rt.h"
#include "libft.h"

int	create_world(t_world *world, char *file_path);
int	validate_arguments(int argc, char *argv[]);
int	set_option(const char *options);

int	init_world(t_world *world, int argc, char *argv[])
{
	t_list	*line_list;

	if (validate_arguments(argc, argv) == FAILURE)
		return (FAILURE);
	line_list = NULL;
	// if (validate_rt_file(&line_list, argv[1]) == FAILURE)
	// 	return (FAILURE);
	world->option_flag = set_option(argv[2]);
	// if (create_world(world, argv[1]) == FAILURE)
		// return (FAILURE);
	return (SUCCESS);
}

void	err_set_option(int c)
{
	err_rt();
	ft_putstr_fd("invalid option -- '", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

int	set_option(const char *options)
{
	static const char	table[] = "p";
	int					bit_flag;
	size_t				i;
	char				*tmp;

	bit_flag = 0;
	i = 1;
	if (!options || options[0] != '-')
		return (0);
	while (options[i])
	{
		tmp = ft_strchr(table, options[i++]);
		if (tmp == NULL)
		{
			err_set_option(options[i - 1]);
			return (0);
		}
		bit_flag |= (tmp - table + 1);
	}
	return (bit_flag);
}
