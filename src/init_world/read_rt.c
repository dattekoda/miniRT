/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:33:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 00:47:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	read_lines_to_list(t_list *cur, int fd);

/*
@brief set line_list from rt_file
*/
void	read_rt_file(t_list **line_list, const char *file_path)
{
	t_list	head;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror_rt("open");
		exit(EXIT_FAILURE);
	}
	if (read_lines_to_list(ft_memset(&head, 0, sizeof(t_list)), fd) == FAILURE)
	{
		ft_lstclear(&head.next, free);
		close(fd);
		exit(EXIT_FAILURE);
	}
	*line_list = head.next;
	close(fd);
	return ;
}

static int	read_lines_to_list(t_list *cur, int fd)
{
	int		gnl_ret;
	char	*line;

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
