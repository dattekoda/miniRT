/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_space_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:43:10 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/22 16:43:27 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_space_join(char *a, char *b)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(a) + ft_strlen(b) + 2;
	dst = ft_calloc(size, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, a, size);
	ft_strlcat(dst, " ", size);
	ft_strlcat(dst, b, size);
	return (dst);
}
