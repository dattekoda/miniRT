/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:47:08 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/28 14:42:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdbool.h>

int	minirt_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;

	if (n == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	while (n && s1_len && s2_len)
	{
		s1_len--;
		s2_len--;
		if (s1[s1_len] != s2[s2_len])
			return (s1[s1_len] - s2[s2_len]);
		n--;
	}
	return (s1[s1_len] - s2[s2_len]);
}

// bool	rt_double_equal(double a, double b)
// {
	
// }
