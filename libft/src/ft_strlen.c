/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:02:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/27 15:00:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
#include <stdio.h>
#include <assert.h>
#include <limits.h>
int main(void)
{
	assert(ft_strlen("A") == 1);
	assert(ft_strlen("ABC") == 3);
	assert(ft_strlen("abcdefghijklmnopqrstuvwxyz") == 26);
	assert(ft_strlen("") == 0);
	assert(ft_strlen("a\nb") == 3);
	assert(ft_strlen("hello\tworld") == 11);
	assert(ft_strlen("abc\0def") == 3);

	char long_str[101];
	for (unsigned int i = 0; i < 100; i++)
		long_str[i] = 'a';
	long_str[100] = '\0';
	assert(ft_strlen(long_str) == 100);

	printf("all test passed\n");
	return (0);
}
*/