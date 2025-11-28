/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:10:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/27 13:18:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (dst_len + src_len);
	i = 0;
	while (i < size - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>
#include <string.h>
#include <assert.h>
int main(void)
{
	char buf[100];
    size_t ret;

    strcpy(buf, "Hello");
    ret = ft_strlcat(buf, " World", sizeof(buf));
    assert(strcmp(buf, "Hello World") == 0);
    assert(ret == strlen("Hello") + strlen(" World"));

    strcpy(buf, "12345");
    ret = ft_strlcat(buf, "6789", 10); 
    assert(strcmp(buf, "123456789") == 0);
    assert(ret == strlen("12345") + strlen("6789"));

    strcpy(buf, "ABC");
    ret = ft_strlcat(buf, "DEFGHI", 7);
    assert(strcmp(buf, "ABCDEF") == 0);
    assert(ret == strlen("ABC") + strlen("DEFGHI"));

    strcpy(buf, "ABCDEFG");
    ret = ft_strlcat(buf, "HIJK", 5);
    assert(ret == 5 + strlen("HIJK"));

    strcpy(buf, "FOO");
    ret = ft_strlcat(buf, "BAR", 0);
    assert(ret == 0 + strlen("BAR"));

    strcpy(buf, "ABC");
    ret = ft_strlcat(buf, "", sizeof(buf));
    assert(strcmp(buf, "ABC") == 0);
    assert(ret == strlen("ABC"));

    strcpy(buf, "");
    ret = ft_strlcat(buf, "XYZ", sizeof(buf));
    assert(strcmp(buf, "XYZ") == 0);
    assert(ret == strlen("XYZ"));

	char weird[5] = {'A', 'B', 'C', 'D', 'E'}; 
	ret = ft_strlcat(weird, "XYZ", 4);
	assert(ret == 4 + 3);

    printf("All ft_strlcat tests passed!\n");
}
*/