/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:13:34 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 21:52:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	l_len = ft_strlen(little);
	i = 0;
	while (big[i] && l_len <= len)
	{
		if (big[i] == *little)
		{
			if (ft_strncmp(&big[i], little, l_len) == 0)
				return ((char *)&big[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}

/*
#include <assert.h>
#include <stdio.h>
int main(void)
{
	char *p1 = "hello";
	char *p2 = "ll";
	
	char *rev1 = ft_strnstr(p1, p2, 10);
	assert(rev1 == p1 + 2);


	char *p3 = "yes";
	char *p4 = "hi";
	
	char *rev2 = ft_strnstr(p3, p4, 10);
	assert(rev2 == NULL);

	char *p5 = NULL;
	char *p6 = NULL;
	
	char *rev3 = ft_strnstr(p5, p6, 10);
	assert(rev3 == NULL);

	printf("passed\n");
	return (0);
}
*/