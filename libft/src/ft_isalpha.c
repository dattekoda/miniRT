/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:31:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/29 20:56:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c);
static int	ft_islower(int c);

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (FT_ISALPHA);
	return (0);
}

static int	ft_isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (FT_ISUPPER);
	return (0);
}

static int	ft_islower(int c)
{
	if ('a' <= c && c <= 'z')
		return (FT_ISLOWER);
	return (0);
}

/*
#include <stdio.h>
#include <assert.h>
#include <limits.h>
int main(void)
{
	assert(ft_isalpha('a'));
	assert(ft_isalpha('z'));
	assert(ft_isalpha('A'));
	assert(ft_isalpha('Z'));

	assert(!ft_isalpha('0'));
	assert(!ft_isalpha('9'));
	assert(!ft_isalpha('/'));
	assert(!ft_isalpha(':'));
	assert(!ft_isalpha('@'));
	assert(!ft_isalpha('['));
	assert(!ft_isalpha('\''));
	assert(!ft_isalpha('{'));
	assert(!ft_isalpha(0));
	assert(!ft_isalpha(127));
	assert(!ft_isalpha(INT_MAX));
	assert(!ft_isalpha(INT_MIN));
	
	printf("all test passed\n");
	return (0);
}
*/