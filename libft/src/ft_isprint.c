/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:58:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 19:30:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

/*
#include <stdio.h>
#include <assert.h>
#include <limits.h>
int main(void)
{
	assert(ft_isprint('a'));
	assert(ft_isprint('z'));
	assert(ft_isprint('A'));
	assert(ft_isprint('Z'));
	assert(ft_isprint('0'));
	assert(ft_isprint('9'));
	assert(ft_isprint('/'));
	assert(ft_isprint(':'));
	assert(ft_isprint('@'));
	assert(ft_isprint('['));
	assert(ft_isprint('\''));
	assert(ft_isprint('{'));

	assert(!ft_isprint(0));
	assert(!ft_isprint(31));
	assert(!ft_isprint(127));
	assert(!ft_isprint(INT_MAX));
	assert(!ft_isprint(INT_MIN));
	
	printf("all test passed\n");
	return (0);
}
*/