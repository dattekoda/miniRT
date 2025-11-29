/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:10:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/11/29 19:13:10 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*tail;

	if (!s1 || !set)
		return (NULL);
	tail = s1 + ft_strlen(s1);
	while (ft_strchr(set, *s1) != NULL)
	{
		if (s1 == tail)
			return (ft_strdup(""));
		s1++;
	}
	while (ft_strrchr(set, *(tail - 1)) != NULL)
		tail--;
	return (ft_strndup(s1, tail - s1));
}

/*
int main(void)
{
	char *s = ft_strtrim("", "\n\t");
	printf("result: %0x\n", (int)s[0]);
	assert(!ft_strncmp("", s, 1));

	s = ft_strtrim("a", "aaaa");
	printf("result: %0x\n", (int)s[0]);
	assert(!ft_strncmp("", s, 1));
	
	s = ft_strtrim("aaa", "\0");
	printf("result: %0x\n", (int)s[0]);
	assert(!ft_strncmp("aaa", s, 1));
	
	s = ft_strtrim("aaa", NULL);
	printf("%s\n", s);
	return (0);
}
*/