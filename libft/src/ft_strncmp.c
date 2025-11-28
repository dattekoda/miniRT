/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:08:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/29 04:21:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <assert.h>
#include <string.h>

void test_ft_strncmp(const char *s1, const char *s2, size_t n) {
    int expected = strncmp(s1, s2, n);
    int actual = ft_strncmp(s1, s2, n);

    if ((expected == 0 && actual != 0) ||
        (expected < 0 && actual >= 0) ||
        (expected > 0 && actual <= 0)) {
        printf("NG: ft_strncmp(\"%s\", \"%s\", %zu)\n", s1, s2, n);
        printf("Expected: %d, Actual: %d\n", expected, actual);
        assert(0);
    }
}


int main(void) {
    test_ft_strncmp("abc", "abc", 3);
    test_ft_strncmp("abc", "xbc", 1);
    test_ft_strncmp("abcdef", "abcxef", 4);
    test_ft_strncmp("abcdef", "abcxef", 5);
    test_ft_strncmp("abc", "abcdef", 5);
    test_ft_strncmp("abcdef", "abc", 5);
    test_ft_strncmp("", "", 1);
    test_ft_strncmp("", "abc", 1);
    test_ft_strncmp("abc", "", 1);
    test_ft_strncmp("ABC", "abc", 3);
    test_ft_strncmp("abc", "ABC", 3);
    test_ft_strncmp("abc!", "abc?", 4);
    test_ft_strncmp("abc ", "abc!", 4);
    test_ft_strncmp("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 50);
    test_ft_strncmp("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", 50);
    test_ft_strncmp("abc", "abc", 0);
	test_ft_strncmp("", "", 0);
    test_ft_strncmp("", "", 1);
    test_ft_strncmp("", "a", 0);
    test_ft_strncmp("a", "", 0);
    test_ft_strncmp("", "a", 1);
    test_ft_strncmp("a", "", 1);
    test_ft_strncmp("abc", "abc", 0);
    test_ft_strncmp("abc", "abd", 0);
    test_ft_strncmp("a", "a\0b", 2);
    test_ft_strncmp("a\0b", "a\0c", 3);

    printf("All tests passed!\n");
    return 0;
}
*/