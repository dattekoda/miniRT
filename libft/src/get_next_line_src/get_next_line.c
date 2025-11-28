/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:55:14 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/29 06:46:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*get_next_line_core(int fd, t_save *save);
static ssize_t	join_read_buf(int fd, t_save *save);
static char		*dup_first_line(t_save *save);
static char		*remove_first_line(t_save *save);

char	*get_next_line(int fd)
{
	char			*next_line;
	t_list			*node_ptr;
	static t_list	*table[HASH_SIZE];

	if (fd < 0)
		return (NULL);
	node_ptr = alloc_fd_node(fd, table);
	if (!node_ptr)
		return (NULL);
	next_line = get_next_line_core(fd, &node_ptr->save);
	if (!next_line || !next_line[0])
		return (free(next_line), free_fd_node(fd, table), NULL);
	return (next_line);
}

static char	*get_next_line_core(int fd, t_save *save)
{
	char	*next_line;
	ssize_t	rd_size;

	next_line = NULL;
	if (!has_new_line(save->data))
	{
		rd_size = join_read_buf(fd, save);
		if (rd_size == -1 || !save->data)
		{
			free(save->data);
			save->data = NULL;
			return (NULL);
		}
	}
	next_line = dup_first_line(save);
	if (!next_line)
	{
		free(save->data);
		save->data = NULL;
		return (NULL);
	}
	save->data = remove_first_line(save);
	return (next_line);
}

static ssize_t	join_read_buf(int fd, t_save *save)
{
	ssize_t	rd_size;
	char	*buf;
	ssize_t	i;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	rd_size = 0;
	while (!has_new_line(save->data + save->str_len - rd_size))
	{
		rd_size = read(fd, buf, BUFFER_SIZE);
		if (rd_size <= 0)
			break ;
		if ((size_t)rd_size > (save->buf_size - save->str_len - 1))
			if (!expand_save(save, rd_size))
				return (free(buf), -1);
		i = -1;
		while (++i < rd_size)
			save->data[save->str_len + i] = buf[i];
		save->data[save->str_len + i] = '\0';
		save->str_len += rd_size;
	}
	return (free(buf), rd_size);
}

static char	*dup_first_line(t_save *save)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (len < save->str_len && save->data[len] != '\n')
		len++;
	if (save->data[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = save->data[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*remove_first_line(t_save *save)
{
	size_t	len;
	size_t	i;

	if (!save->data)
		return (NULL);
	len = 0;
	while (save->data[len] && save->data[len] != '\n')
		len++;
	if (save->data[len] == '\n')
		len++;
	i = 0;
	while (save->data[len + i])
	{
		save->data[i] = save->data[len + i];
		i++;
	}
	save->data[i] = '\0';
	save->str_len -= len;
	return (save->data);
}
