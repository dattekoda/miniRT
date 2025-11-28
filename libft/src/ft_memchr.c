/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:21:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 20:06:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return (p + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
int main(void)
{
    char buf1[] = "abcde";
	assert(memchr(buf1, 'a', 5) == buf1);
    assert(memchr(buf1, 'c', 5) == buf1 + 2);
	assert(memchr(buf1, 'e', 5) == buf1 + 4);
    assert(memchr(buf1, 'z', 5) == NULL);
    assert(memchr(buf1, 'a', 0) == NULL);
    assert(memchr(buf1, 'e', 4) == NULL);
	
    char buf2[] = {'a', 'b', '\0', 'd', 'e'};
    assert(memchr(buf2, '\0', 5) == buf2 + 2);
    assert(memchr(buf2, '\0', 2) == NULL);
	
    unsigned char buf3[] = {0xfe, 0xfd, 0xfc};
    assert(memchr(buf3, (unsigned char)0xfe, 3) == buf3);
	
    unsigned char buf4[] = {1, 2, 3, 4};
    assert(memchr(buf4, 5, 4) == NULL);
	
    unsigned char buf5[] = {0x00, 0xff, 0x02};
    assert(memchr(buf5, 0xff, 3) == buf5 + 1);
	
    printf("All tests passed!\n");
}
*/