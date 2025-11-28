/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 01:09:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/12 14:41:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

int	pad_char(char c, int len)
{
	while (len-- > 0)
	{
		if (ft_putchar_safe(c) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putchar_safe(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (0);
}
