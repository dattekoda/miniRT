/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:06:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/12 14:44:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

static void		make_numstr_x(long n, char *arr, size_t size, int is_upper);
static size_t	count_digits_x(long n);
char			*ltox(long n, int is_upper);

char	*ltox(long n, int is_upper)
{
	char	*res;
	size_t	digit;

	digit = count_digits_x(n);
	res = ft_calloc(digit + 1, sizeof(char));
	if (!res)
		return (NULL);
	make_numstr_x(n, res, digit, is_upper);
	return (res);
}

static void	make_numstr_x(long n, char *arr, size_t size, int is_upper)
{
	long	tmp;
	char	hex_base[17];

	if (is_upper)
		ft_strlcpy(hex_base, "0123456789ABCDEF", 17);
	else
		ft_strlcpy(hex_base, "0123456789abcdef", 17);
	arr[size--] = '\0';
	if (n == 0)
	{
		arr[0] = '0';
		return ;
	}
	while (n != 0)
	{
		tmp = n % 16;
		arr[size] = hex_base[tmp];
		n /= 16;
		size--;
	}
}

static size_t	count_digits_x(long n)
{
	size_t	digit;

	if (n == 0)
		return (1);
	digit = 0;
	while (n != 0)
	{
		n /= 16;
		digit++;
	}
	return (digit);
}
