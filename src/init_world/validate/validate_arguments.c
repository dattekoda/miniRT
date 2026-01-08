/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:05:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 12:06:27 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int			validate_file_name(const char *argv_one);

/*
@brief validate function
@param argv_one argv[1]
*/
void	validate_arguments(int argc, char *argv[])
{
	if (argc == 1)
	{
		err_rt();
		ft_putendl_fd("set .rt file as first argument", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (validate_file_name(argv[1]) == FAILURE)
		exit(EXIT_FAILURE);
	return ;
}
