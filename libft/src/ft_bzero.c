/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:28:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 19:29:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = '\0';
}

/*
#include <stdio.h>
#include <assert.h>

int main(void)
{
    char buf[10] = "abcdefghi";

    ft_bzero(buf, 5);
    for (int i = 0; i < 5; i++)
        assert(buf[i] == '\0');
    for (int i = 5; i < 9; i++)  
        assert(buf[i] != '\0');

    char buf2[5] = "1234";
    ft_bzero(buf2, 0);
    assert(buf2[0] == '1');  
    assert(buf2[1] == '2');
    assert(buf2[2] == '3');
    assert(buf2[3] == '4');

    char buf3[6] = "hello";
    ft_bzero(buf3 + 2, 3);
    assert(buf3[0] == 'h');
    assert(buf3[1] == 'e');
    assert(buf3[2] == '\0');
    assert(buf3[3] == '\0');
    assert(buf3[4] == '\0');

    char buf4[100];
	for (unsigned int i = 0; i < 100; i++)
		buf4[i] = 'a';
    ft_bzero(buf4, 100);
    for (int i = 0; i < 100; i++)
        assert(buf4[i] == '\0');

    printf("all tests passed\n");
    return 0;
}
*/