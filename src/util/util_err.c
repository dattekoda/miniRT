/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:19:05 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/05 10:27:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "libft.h"
#include <stdlib.h>

/*
@brief Used as a prefix for all error messages
*/
void	err_rt(void)
{
	ft_putstr_fd(ERR_MSG_MINIRT, STDERR_FILENO);
}
