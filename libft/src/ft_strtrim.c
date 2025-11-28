/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:10:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 22:23:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t len);

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

static char	*ft_strndup(const char *s, size_t len)
{
	char	*rev;

	rev = ft_calloc(len + 1, sizeof(char));
	if (rev == NULL)
		return (NULL);
	ft_strlcpy(rev, s, len + 1);
	return (rev);
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