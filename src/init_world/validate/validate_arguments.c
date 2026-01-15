/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:21:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 12:22:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <stdlib.h>

static int	validate_file_name(const char *file_path);

/*
@brief validate function
@param argv_one argv[1]
*/
static void	validate_arguments(int argc, char *argv[])
{
	if (argc == 1)
	{
		err_rt("set .rt file as first argument");
		exit(EXIT_FAILURE);
	}
	if (validate_file_name(argv[1]) == FAILURE)
		exit(EXIT_FAILURE);
	return ;
}

/*
@brief Check if the file name of argument is correct.
@param file_path just argv[1]
*/
static int	validate_file_name(const char *file_path)
{
	size_t		rt_file_len;
	const char	*rt_file;

	rt_file = ft_strchr(file_path, '/');
	if (rt_file)
		rt_file += 1;
	else
		rt_file = file_path;
	rt_file_len = ft_strlen(rt_file);
	if ((rt_file[0] == '.') 
	|| (rt_file_len <= 3 || ft_strcmp(rt_file + rt_file_len - 3, ".rt") != 0))
	{
		err_rt("invalid file name");
		return (FAILURE);
	}
	return (SUCCESS);
}
