/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:19:05 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 23:25:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
@brief Used as a prefix for all error messages
*/
void	err_rt(void)
{
	ft_putstr_fd("miniRT: ", STDERR_FILENO);
}

void	perror_rt(const char *syscall_fname)
{
	err_rt();
	perror(syscall_fname);
}
