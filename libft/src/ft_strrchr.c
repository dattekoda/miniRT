/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:00:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 21:54:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len + 1 > 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
int main(void)
{
	const char *str = "hello";
    assert(ft_strrchr(str, 'e') == str + 1); 
    assert(ft_strrchr(str, 'l') == str + 3);
    assert(ft_strrchr(str, 'o') == str + 4);
    assert(ft_strrchr(str, 'x') == NULL);
    assert(ft_strrchr(str, '\0') == str + 5);
	const char *emp = "";
    assert(ft_strrchr(emp, 'a') == NULL);
	assert(ft_strrchr(emp, '\0') == emp);

    printf("All tests passed!\n");
}
*/