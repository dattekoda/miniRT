/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:24:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 22:59:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*
#include <assert.h>
#include <stdio.h>
int main(void)
{
	{
		char s1[] = "abcabc";
		char s2[] = "abcxyz";
		assert(ft_memcmp(s1, s2, 3) == 0);
		assert(ft_memcmp(s1, s2, 6) < 0);
		assert(ft_memcmp(s2, s1, 6) > 0);
	}
	{
		char s1[] = "hello";
		char s2[] = "hello";
		assert(ft_memcmp(s1, s2, 3) == 0);
		assert(ft_memcmp(s1, s2, 5) == 0);
	}
	{
		char s1[] = {'a', '\0', 'b'};
		char s2[] = {'a', '\0', 'b'};
		assert(ft_memcmp(s1, s2, 3) == 0);
	}	
	{
		char s1[] = {'a', 'b', '\0', 'd', 'e'};
		char s2[] = {'a', 'b', '\0', 'x', 'y'};
		assert(ft_memcmp(s1, s2, 3) == 0);
		assert(ft_memcmp(s1, s2, 4) < 0);
		assert(ft_memcmp(s2, s1, 4) > 0);
	}
	{
		char s1[] = "abcde";
		char s2[] = "abc";
		assert(ft_memcmp(s1, s2, 3) == 0);
		assert(ft_memcmp(s1, s2, 5) > 0);
		assert(ft_memcmp(s2, s1, 5) < 0);
	}
	{
		char s1[] = "abc";
		char s2[] = "xyz";
		assert(ft_memcmp(s1, s2, 0) == 0);
	}
	{
		unsigned char s1[] = {0x01, 0xFF, 0x03};
		unsigned char s2[] = {0x01, 0x00, 0x03};
		assert(ft_memcmp(s1, s2, 2) > 0);
		assert(ft_memcmp(s2, s1, 2) < 0);
	}
	
	printf("all tests passed.\n");
	return (0);
}
*/