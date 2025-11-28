/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 04:13:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/12 14:42:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_vprintf(const char *fmt, va_list ap);
static int	printf_main(const char **fmt, va_list ap);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		reval;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	reval = ft_vprintf(fmt, ap);
	va_end(ap);
	if (reval == ERROR)
		return (-1);
	return (reval);
}

static int	ft_vprintf(const char *fmt, va_list ap)
{
	int		cnt;
	int		total_len;

	total_len = 0;
	while (*fmt)
	{
		cnt = printf_main(&fmt, ap);
		if (cnt == ERROR)
			return (ERROR);
		if (cnt > INT_MAX - total_len)
			return (ERROR);
		total_len += cnt;
	}
	return (total_len);
}

static int	printf_main(const char **fmt, va_list ap)
{
	int		reval;

	if (**fmt != '%')
	{
		if (ft_putchar_safe(**fmt) == -1)
			return (ERROR);
		(*fmt)++;
		return (1);
	}
	else
	{
		(*fmt)++;
		reval = convert_specifier(fmt, ap);
		return (reval);
	}
}
