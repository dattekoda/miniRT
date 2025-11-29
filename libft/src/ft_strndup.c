/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:58:18 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/29 18:46:03 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ndup;
	size_t	ndup_len;

	ndup_len = ft_strlen(s);
	if (ndup_len < n)
		n = ndup_len;
	ndup = calloc(n + 1, sizeof(char));
	if (!ndup)
		return (NULL);
	ft_memmove(ndup, s, n);
	return (ndup);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	s[11] = "hel\nloworld";
// 	char	*t;

// 	t = ft_strndup(s, 4);
// 	printf("%s", t);
// 	return (free(t), 0);
// }