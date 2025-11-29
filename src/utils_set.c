/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:49:15 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/29 18:19:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "miniRT_struct.h"
#include "libft.h"
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>

int	set_content(char **content, const char *file_name)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	char	*tmp;
	ssize_t	rd_size;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("open"), EXIT_FAILURE);
	*content = calloc(1, sizeof(char));
	if (!*content)
		return (close(fd), perror("malloc"), EXIT_FAILURE);
	while (*content && rd_size)
	{
		rd_size = read(fd, buf, BUFFER_SIZE - 1);
		if (rd_size == -1)
			return (close(fd), perror("read"), EXIT_FAILURE);
		buf[rd_size] = 0;
		tmp = *content;
		*content = ft_strjoin(*content, buf);
		free(tmp);
	}
	if (!*content)
		return (close(fd), perror("malloc"), EXIT_FAILURE);
	return (close(fd), EXIT_SUCCESS);
}

// t_data	*new_t_data(const char *line)
// {
// 	size_t	i;
// 	i = 0;
// }
