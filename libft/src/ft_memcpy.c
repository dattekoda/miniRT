/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:42:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/29 03:36:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*
#include <stdio.h>
#include <assert.h>

int main(void)
{
    char src1[] = "hello";
    char dst1[6] = {0};
    assert(ft_memcpy(dst1, src1, 6) == dst1);
    assert(ft_memcmp(dst1, src1, sizeof(src1)) == 0);

    char src2[] = "abc";
    char dst2[] = "xxx";
    assert(ft_memcpy(dst2, src2, 0) == dst2);
	assert(ft_memcmp(dst2, "xxx", 3) == 0);

    char src3[] = "world";
    char dst3[] = "XXXXX";
    assert(ft_memcpy(dst3, src3, 3) == dst3);
    assert(dst3[0] == 'w');
    assert(dst3[1] == 'o');
    assert(dst3[2] == 'r');
    assert(dst3[3] == 'X');
    assert(dst3[4] == 'X');

    char src4[100];
    char dst4[100];
    for (int i = 0; i < 100; i++)
        src4[i] = (char)(i % 128);
    assert(ft_memcpy(dst4, src4, 100) == dst4);
	assert(ft_memcmp(dst4, src4, sizeof(src4)) == 0);

	unsigned char src5[] = {'a', 'b', 'c', 'A', '_' ,0x00,  0x88, 0xff, 
							'a', 'b', 'c'};
	int		n = 6;
	int		size = 20;
	unsigned char	dst5[size];

	ft_bzero(dst5, size);
	assert(ft_memcpy(dst5, src5, n) == dst5);
	
    for (int i = 0; i < n; i++)
        assert(dst5[i] == src5[i]);

    for (int i = n; i < size; i++)
        assert(dst5[i] == 0x00);

	assert(ft_memcpy(NULL, NULL, 0) == NULL);
	assert(ft_memcpy(NULL, "abc", 0) == NULL);
	assert(ft_memcpy("abc", NULL, 0) != NULL);
	assert(ft_memcpy(NULL, NULL, 1) == NULL);
	// assert(ft_memcpy(NULL, "abc", 1) == NULL);
	// assert(ft_memcpy("abc", NULL, 1) != NULL);

    printf("all tests passed\n");
    return 0;
}
*/