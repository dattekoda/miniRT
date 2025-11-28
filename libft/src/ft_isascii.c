/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:55:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 19:30:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (FT_ISASCII);
	return (0);
}

/*
#include <stdio.h>
#include <assert.h>
#include <limits.h>
int main(void)
{
	assert(ft_isascii('a'));
	assert(ft_isascii('z'));
	assert(ft_isascii('A'));
	assert(ft_isascii('Z'));
	assert(ft_isascii('0'));
	assert(ft_isascii('9'));
	assert(ft_isascii('/'));
	assert(ft_isascii(':'));
	assert(ft_isascii('@'));
	assert(ft_isascii('['));
	assert(ft_isascii('\''));
	assert(ft_isascii('{'));
	assert(ft_isascii(0));
	assert(ft_isascii(127));
	
	assert(!ft_isascii(INT_MAX));
	assert(!ft_isascii(INT_MIN));
	
	printf("all test passed\n");
	return (0);
}
*/