/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:03:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 20:09:32 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
		ft_memcpy(d, s, n);
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_normal_string_copy(void)
{
    char src[] = "abcdef";
    char dst[10] = {0};

    assert(ft_memmove(dst, src, sizeof(src)) == dst);
    assert(memcmp(dst, "abcdef", sizeof(src)) == 0);
}

void test_size_zero_copy(void)
{
    char src[] = "abcdef";
    char dst[] = "123456";

    assert(ft_memmove(dst, src, 0) == dst);
    assert(memcmp(dst, "123456", sizeof("123456")) == 0);
}

void test_self_copy(void)
{
    char buf[] = "abcdef";

    assert(ft_memmove(buf, buf, 6) == buf);
    assert(memcmp(buf, "abcdef", sizeof("abcdef")) == 0);
}

void test_overlap_dest_before_src_string(void)
{
    char buf[20] = "abcdef";

    assert(ft_memmove(buf, buf + 2, 4) == buf);
    assert(memcmp(buf, "cdefef", 6) == 0);
}

void test_overlap_dest_after_src_string(void)
{
    char buf[20] = "abcdef";

    assert(ft_memmove(buf + 2, buf, 4) == buf + 2);
    assert(memcmp(buf, "ababcd", 6) == 0);
}

void test_one_byte_copy_string(void)
{
    char buf[10] = "abc";

    assert(ft_memmove(buf + 1, buf, 1) == buf + 1);
    assert(memcmp(buf, "aac", 3) == 0);
}

void test_binary_normal_copy(void)
{
    unsigned char src[] = {'a', 'b', 'c', 'A', '_', 0x00, 0x88, 0xff};
    unsigned char dst[10] = {0};

    assert(ft_memmove(dst, src, 8) == dst);
    for (int i = 0; i < 8; i++)
        assert(dst[i] == src[i]);
}

void test_overlap_dest_after_src_binary(void)
{
    unsigned char buf[20] = {'x', 'y', 'z', '1', '2', 0x00, 0x11, 0x22};
    assert(ft_memmove(buf + 1, buf, 5) == buf + 1);

    unsigned char expected[] = {'x', 'x', 'y', 'z', '1', '2', 0x11, 0x22};
    for (int i = 0; i < 8; i++)
        assert(buf[i] == expected[i]);
}

void test_overlap_dest_before_src_binary(void)
{
    unsigned char buf[20] = {'x', 'y', 'z', '1', '2', 0x00, 0x11, 0x22};
    assert(ft_memmove(buf, buf + 2, 5) == buf);

    unsigned char expected[] = {'z', '1', '2', 0x00, 0x11};
    for (int i = 0; i < 5; i++)
        assert(buf[i] == expected[i]);
}

void test_one_byte_copy_binary(void)
{
    unsigned char buf[10] = {0x00, 0xff, 'c'};
    assert(ft_memmove(buf + 1, buf, 1) == buf + 1);

    assert(buf[0] == 0x00);
    assert(buf[1] == 0x00);
    assert(buf[2] == 'c');
}

void test_memove_zero_copy_with_NULL(void){
	assert(ft_memmove(NULL, NULL, 0) == NULL);
}

int main(void)
{
    test_normal_string_copy();
    test_size_zero_copy();
    test_self_copy();
    test_overlap_dest_after_src_string();
    test_overlap_dest_before_src_string();
    test_one_byte_copy_string();
    test_binary_normal_copy();
    test_overlap_dest_after_src_binary();
    test_overlap_dest_before_src_binary();
    test_one_byte_copy_binary();
	test_memove_zero_copy_with_NULL();

    printf("All tests passed.\n");
    return 0;
}
*/