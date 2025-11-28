/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:42:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/11 16:42:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		make_numstr(long nbr, char *arr, size_t size);
static size_t	count_digits(long n);

char	*ft_ltoa(long n)
{
	char	*res;
	size_t	digit;

	digit = count_digits(n);
	res = ft_calloc(digit + 1, sizeof(char));
	if (!res)
		return (NULL);
	make_numstr(n, res, digit);
	return (res);
}

static void	make_numstr(long nbr, char *arr, size_t size)
{
	long	tmp;
	long	n;

	arr[size--] = '\0';
	if (nbr == 0)
	{
		arr[0] = '0';
		return ;
	}
	n = nbr;
	while (n != 0)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp = -tmp;
		arr[size] = '0' + tmp;
		n /= 10;
		size--;
	}
	if (nbr < 0)
		arr[size] = '-';
}

static size_t	count_digits(long n)
{
	size_t	digit;

	if (n == 0)
		return (1);
	digit = 0;
	if (n < 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
