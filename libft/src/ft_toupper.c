/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:20:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/04/29 21:12:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c += ('A' - 'a');
	return (c);
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
    assert(ft_toupper('a') == 'A');
    assert(ft_toupper('z') == 'Z');
    assert(ft_toupper('m') == 'M');
    assert(ft_toupper('A') == 'A');
    assert(ft_toupper('Z') == 'Z');
    assert(ft_toupper('0') == '0');
    assert(ft_toupper('9') == '9');
    assert(ft_toupper('!') == '!');
    assert(ft_toupper('@') == '@');
    assert(ft_toupper(' ') == ' ');
    assert(ft_toupper(0) == 0);
    assert(ft_toupper(127) == 127);

    printf("all test passed\n");
    return (0);
}
*/