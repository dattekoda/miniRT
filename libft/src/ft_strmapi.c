/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:46:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/30 00:04:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (NULL);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// テスト用の関数 (indexが偶数なら大文字に、奇数なら小文字にする)
char test_func(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (c >= 'a' && c <= 'z') ? c - 32 : c;
    else
        return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

// テスト用の関数 (すべて'x'に変換する)
char set_x(unsigned int i, char c)
{
    (void)i;
    (void)c;
    return 'x';
}

int main(void)
{
    char *s;
    char *result;

    // ① 普通の文字列でテスト
    s = "abcdef";
    result = ft_strmapi(s, test_func);
    if (result)
    {
        printf("input:  \"%s\"\n", s);
        printf("output: \"%s\"\n", result);
        free(result);
    }
    else
        printf("Test1 failed: returned NULL\n");

    // ② 空文字列でテスト
    s = "";
    result = ft_strmapi(s, test_func);
    if (result)
    {
        printf("input:  \"%s\"\n", s);
        printf("output: \"%s\"\n", result);
        free(result);
    }
    else
        printf("Test2 failed: returned NULL\n");

    // ④ すべて'x'に変換する関数でテスト
    s = "12345";
    result = ft_strmapi(s, set_x);
    if (result)
    {
        printf("input:  \"%s\"\n", s);
        printf("output: \"%s\"\n", result);
        free(result);
    }
    else
        printf("Test4 failed: returned NULL\n");

    return 0;
}
*/