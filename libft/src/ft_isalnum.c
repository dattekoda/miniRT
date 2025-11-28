/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:47:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/29 19:26:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (FT_ISALNUM);
	return (0);
}

/*
#include <stdio.h>
#include <assert.h>
#include <limits.h>
int main(void)
{
	assert(ft_isalnum('a'));
	assert(ft_isalnum('z'));
	assert(ft_isalnum('A'));
	assert(ft_isalnum('Z'));
	assert(ft_isalnum('0'));
	assert(ft_isalnum('9'));
	
	assert(!ft_isalnum('/'));
	assert(!ft_isalnum(':'));
	assert(!ft_isalnum('@'));
	assert(!ft_isalnum('['));
	assert(!ft_isalnum('\''));
	assert(!ft_isalnum('{'));
	assert(!ft_isalnum(0));
	assert(!ft_isalnum(127));
	assert(!ft_isalnum(INT_MAX));
	assert(!ft_isalnum(INT_MIN));
	
	printf("all test passed\n");
	return (0);
}
*/