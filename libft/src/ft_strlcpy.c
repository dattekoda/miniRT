/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:21:16 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 11:20:37 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// #include <bsd/string.h>
// #include <stdio.h>
// int	main(void) {
// 	char dst[10];
// 	char src[100] = "ohayo sayonara ohayo sayonara ohayo sayonara";
// 	ft_strlcpy(dst, src, 8);
// 	printf("%s\n", dst);
// 	return 0;
// }