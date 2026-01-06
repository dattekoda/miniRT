/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:08:58 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 19:03:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "libft.h"

void	err_spaces(void (*f)(void))
{
	f();
	ft_putendl_fd("need spaces", STDERR_FILENO);
}

void	err_range(void (*f)(void), int min, int max)
{
	f();
	ft_putstr_fd("range ", STDERR_FILENO);
	ft_putnbr_fd(min, STDERR_FILENO);
	ft_putchar_fd('-', STDERR_FILENO);
	ft_putnbr_fd(max, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	err_vec(void (*f)(void), t_vectype type)
{
	f();
	if (type == IS_POINT)
		ft_putendl_fd("use 'a,b,c' format", STDERR_FILENO);
	else if (type == IS_UNIT)
		ft_putendl_fd("unit vector's values range 0-1", STDERR_FILENO);
	else if (type == IS_COLOR)
		ft_putendl_fd("RGB values range 0-255", STDERR_FILENO);
}
