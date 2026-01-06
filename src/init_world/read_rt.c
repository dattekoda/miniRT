/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:33:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 16:35:37 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

static int	set_head_list(t_list *cur, int fd);

/*
@brief set line_list from rt_file
*/
int	read_rt_file(t_list **line_list, const char *file_path)
{
	t_list	head;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (perror_rt("open"), FAILURE);
	if (set_head_list(ft_memset(&head, 0, sizeof(t_list)), fd))
		return (ft_lstclear(&head.next, free), close(fd), FAILURE);
	*line_list = head.next;
	return (close(fd), SUCCESS);
}

static int	set_head_list(t_list *cur, int fd)
{
	int		gnl_ret;
	char	*line;

	gnl_ret = 1;
	line = NULL;
	while (cur)
	{
		gnl_ret = ft_get_next_line(fd, &line);
		if (gnl_ret == -1)
			return (perror_rt("read"), FAILURE);
		if (gnl_ret == -2)
			return (perror_rt("malloc"), FAILURE);
		if (gnl_ret == 0)
			break ;
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		cur->next = ft_lstnew(line);
		cur = cur->next;
	}
	if (!cur)
		return (perror_rt("malloc"), FAILURE);
	return (SUCCESS);
}
