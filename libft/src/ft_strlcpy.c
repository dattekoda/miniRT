/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:28:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/27 15:00:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

size_t ft_strlcpy(char *dst, const char *src, size_t size); // ←あなたの再実装関数

int main(void)
{
    char buf[100];

    strcpy(buf, "XXXXXXXX");
    assert(ft_strlcpy(buf, "abc", 10) == 3);
    assert(strcmp(buf, "abc") == 0);

    strcpy(buf, "XXXXXXXX");
    assert(ft_strlcpy(buf, "hello", 6) == 5);
    assert(strcmp(buf, "hello") == 0);

    strcpy(buf, "XXXXXXXX");
    assert(ft_strlcpy(buf, "abcdef", 4) == 6);
    assert(buf[0] == 'a' && buf[1] == 'b' && buf[2] == 'c' && buf[3] == '\0');

    strcpy(buf, "XXXXXXXX");
    assert(ft_strlcpy(buf, "test", 0) == 4);
    assert(strcmp(buf, "XXXXXXXX") == 0); 

    strcpy(buf, "XXXXXXXX");
    assert(ft_strlcpy(buf, "", 5) == 0);
    assert(buf[0] == '\0');

    strcpy(buf, "abcdef");
    assert(ft_strlcpy(buf, buf, 7) == 6);
    assert(strcmp(buf, "abcdef") == 0);

    printf("all tests passed.\n");
    return 0;
}
*/