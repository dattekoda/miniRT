/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:21:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 02:24:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_utils.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	put_format(void);
bool		is_valid_file_name(const char *file_path);
bool		is_valid_option(char **options);

/*
@brief validate function
@param argv_one argv[1]
*/
void	validate_arguments(int argc, char *argv[])
{
	if (argc == 1)
	{
		err_rt("set .rt file as first argument");
		put_format();
		exit(EXIT_FAILURE);
	}
	if (!is_valid_file_name(argv[1]))
		exit(EXIT_FAILURE);
	if (argc >= 3 && !is_valid_option(argv + 2))
		exit(EXIT_FAILURE);
	return ;
}

static void	put_format(void)
{
	size_t	i;

	i = 0;
	while (g_info_table[i])
		ft_putendl_fd(g_info_table[i++]->input_format, STDERR_FILENO);
	return ;
}
