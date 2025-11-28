/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:39:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 21:46:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (i < len + 1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <assert.h>
int main(void)
{
	const char *str = "hello";
    assert(ft_strchr(str, 'e') == str + 1); 
    assert(ft_strchr(str, 'l') == str + 2);
    assert(ft_strchr(str, 'o') == str + 4);
    assert(ft_strchr(str, 'x') == NULL);
    assert(ft_strchr(str, '\0') == str + 5);
    assert(ft_strchr("", 'a') == NULL);

    printf("All tests passed!\n");
}
*/