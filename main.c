/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:03:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/14 12:24:00 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "libft.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

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

int	main(int argc, char *argv[])
{
	if (argc != ARG_NUM)
		return (MINIRT_FAILURE);
	if (minirt_strrncmp(argv[1], ".md", 3))
		return (MINIRT_FAILURE);
	int	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (MINIRT_FAILURE);
	}
	close(fd);
	return (MINIRT_SUCCESS);
}
