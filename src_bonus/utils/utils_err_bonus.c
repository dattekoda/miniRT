/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_err_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:19:05 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_bonus.h"
#include "rt_config_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
@brief Used as a prefix for all error messages
*/
void	err_rt(char *err_msg)
{
	ft_putstr_fd(PROJECT_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (err_msg)
		ft_putendl_fd(err_msg, STDERR_FILENO);
}

void	perror_rt(const char *syscall_fname)
{
	err_rt(NULL);
	perror(syscall_fname);
}
