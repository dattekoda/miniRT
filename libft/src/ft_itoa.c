/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:42:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 21:33:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		make_numstr(int n, char *arr, size_t size);
static size_t	count_digits(int n);
static char		*ft_strcpy(char *dest, const char *src);

char	*ft_itoa(int n)
{
	char	*res;
	size_t	digit;

	digit = count_digits(n);
	res = ft_calloc(digit + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (n == 0)
		return (ft_strcpy(res, "0"));
	make_numstr(n, res, digit);
	return (res);
}

static void	make_numstr(int nbr, char *arr, size_t size)
{
	int	tmp;
	int	n;

	arr[size--] = '\0';
	n = nbr;
	while (n != 0)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp = -tmp;
		arr[size--] = '0' + tmp;
		n /= 10;
	}
	if (nbr < 0)
		arr[size] = '-';
}

static size_t	count_digits(int n)
{
	size_t	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	if (n < 0)
		cnt++;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-200));
	return(0);
}
*/