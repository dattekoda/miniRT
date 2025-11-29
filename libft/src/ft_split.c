/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:52:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/11/29 19:13:29 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *p, const char c);
static void		*free_all(char **arr);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*head;
	size_t	i;

	if (!s)
		return (NULL);
	arr = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		head = (char *)s;
		while (*s && *s != c)
			s++;
		if (head == s)
			break ;
		arr[i] = ft_strndup(head, s - head);
		if (!arr[i++])
			return (free_all(arr));
	}
	arr[i] = NULL;
	return (arr);
}

static void	*free_all(char **arr)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static size_t	count_words(const char *p, const char c)
{
	size_t	nwords;

	nwords = 0;
	while (*p)
	{
		while (*p && *p == c)
			p++;
		if (*p != '\0')
			nwords++;
		while (*p && *p != c)
			p++;
	}
	return (nwords);
}

/*
int main(void)
{
	char **arr;
	int	i = 0;
	arr = ft_split("aaa", 'a');
	while (arr[i])
	{
		printf("%d: %s\n", i, arr[i]); 
		i++;
	}
	free_all(arr);

	i = 0;
	arr = ft_split("ab cd ef ", "\0");
	while (arr[i])
	{
		printf("%d: %s\n", i, arr[i]); 
		i++;
	}
	free_all(arr);
	return (0);
}
	*/