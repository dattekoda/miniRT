/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 08:42:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/26 10:38:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (FT_ISDIGIT);
	return (0);
}

/*
#include <stdio.h>
#include <assert.h>
#include <limits.h>
int main(void)
{
	assert(ft_isdigit('0'));
	assert(ft_isdigit('9'));

	assert(!ft_isdigit('a'));
	assert(!ft_isdigit('z'));
	assert(!ft_isdigit('A'));
	assert(!ft_isdigit('Z'));
	assert(!ft_isdigit('/'));
	assert(!ft_isdigit(':'));
	assert(!ft_isdigit('@'));
	assert(!ft_isdigit('['));
	assert(!ft_isdigit('\''));
	assert(!ft_isdigit('{'));
	assert(!ft_isdigit(0));
	assert(!ft_isdigit(127));
	assert(!ft_isdigit(INT_MAX));
	assert(!ft_isdigit(INT_MIN));
	
	printf("all test passed\n");
	return (0);
}
*/