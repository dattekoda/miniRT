/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:05:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 17:04:39 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "libft.h"
#include <stdlib.h>

static void	err_argc(void);
int			validate_file_name(const char *argv_one);

/*
@brief validate function
@param argv_one argv[1]
*/
int	validate_arguments(int argc, char *argv[])
{
	if (argc == 1)
		return (err_argc(), FAILURE);
	if (validate_file_name(argv[1]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	err_argc(void)
{
	err_rt();
	ft_putendl_fd("set .rt file as an argument.", STDERR_FILENO);
}
