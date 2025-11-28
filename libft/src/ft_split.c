/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:52:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/02 22:53:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *p, const char c);
static void		*free_all(char **arr);
static char		*ft_strndup(const char *s, size_t len);

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

static char	*ft_strndup(const char *s, size_t len)
{
	char	*rev;
	size_t	i;

	if (!s)
		return (NULL);
	rev = ft_calloc(len + 1, sizeof(char));
	if (rev == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		rev[i] = s[i];
		i++;
	}
	rev[i] = '\0';
	return (rev);
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