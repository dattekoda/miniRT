/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:48:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/12 14:47:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

static void		make_numstr_p(uintptr_t n, char *arr, size_t size);
static size_t	count_digits_p(uintptr_t n);

char	*ptox(uintptr_t p)
{
	char	*res;
	size_t	digit;

	if (p == 0)
		return (NULL);
	digit = count_digits_p(p);
	res = ft_calloc(digit + 1, sizeof(char));
	if (!res)
		return (NULL);
	make_numstr_p(p, res, digit);
	return (res);
}

static void	make_numstr_p(uintptr_t n, char *arr, size_t size)
{
	unsigned int	tmp;
	char			hex_base[17];

	ft_strlcpy(hex_base, "0123456789abcdef", 17);
	if (n == 0)
		return ;
	arr[size--] = '\0';
	while (n != 0)
	{
		tmp = n % 16;
		arr[size] = hex_base[tmp];
		n /= 16;
		size--;
	}
}

static size_t	count_digits_p(uintptr_t n)
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
