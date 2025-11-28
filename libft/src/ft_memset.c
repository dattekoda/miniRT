/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:50:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 20:10:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = c;
	return (s);
}

/*
#include <stdio.h>
#include <assert.h>
int main(void)
{
    char buf[10] = "AAAAAAAAAA";
    ft_memset(buf, 'B', 5);
    for (int i = 0; i < 5; i++)
        assert(buf[i] == 'B');
	for (int j = 5; j < 10; j++)
        assert(buf[j] == 'A');


    char buf2[5] = "1234";
    ft_memset(buf2, 'B', 0);
    assert(buf2[0] == '1');
    assert(buf2[1] == '2');
    assert(buf2[2] == '3');
    assert(buf2[3] == '4');

    char buf3[5] = "abcd";
    ft_memset(buf3, 0, 4);
    for (int i = 0; i < 4; i++)
        assert(buf3[i] == '\0');

    unsigned char buf4[5];
    ft_memset(buf4, 255, 5);
    for (int i = 0; i < 5; i++)
        assert(buf4[i] == 0xFF);

    char buf5[5];
    void *ret = ft_memset(buf5, 'C', 5);
    assert(ret == buf5);

    char buf6[100];
    ft_memset(buf6, 'X', 100);
    for (int i = 0; i < 100; i++)
        assert(buf6[i] == 'X');

    printf("all tests passed\n");
    return 0;
}
*/