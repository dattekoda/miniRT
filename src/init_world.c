/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:26:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 15:33:53 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "util_rt.h"
#include "libft.h"
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

int			create_world(t_world *world, char *file_path);
int			validate_arguments(int argc, char *argv[]);
int			set_option(const char *options);
int			validate_rt_file(const t_list *line_list);
static void	err_invalid_option(void);
static void	err_set_option(int c);
static int	read_rt_file(t_list **line_list, const char *file_path);

// if (validate_rt_file(&line_list, argv[1]) == FAILURE)
// 	return (FAILURE);
// if (create_world(world, argv[1]) == FAILURE)
// 	return (FAILURE);
int	init_world(t_world *world, int argc, char *argv[])
{
	t_list	*line_list;

	if (validate_arguments(argc, argv) == FAILURE)
		return (FAILURE);
	if (read_rt_file(&line_list, argv[1]))
		return (FAILURE);
	if (validate_rt_file(line_list))
		return (FAILURE);
	line_list = NULL;
	world->option_flag = set_option(argv[2]);
	return (SUCCESS);
}

/*
@brief set option like -p
*/
int	set_option(const char *options)
{
	static const char	table[] = "p";
	int					bit_flag;
	size_t				i;
	char				*tmp;

	if (!options)
		return (0);
	if (options[0] != '-')
		return (err_invalid_option(), 0);
	bit_flag = 0;
	i = 1;
	while (options[i])
	{
		tmp = ft_strchr(table, options[i++]);
		if (tmp == NULL)
		{
			err_set_option(options[i - 1]);
			return (0);
		}
		bit_flag |= (1 << (tmp - table));
	}
	return (bit_flag);
}

static void	err_invalid_option(void)
{
	err_rt();
	ft_putendl_fd("option needs to start with '-'", STDERR_FILENO);
}

static void	err_set_option(int c)
{
	err_rt();
	ft_putstr_fd("invalid option -- '", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

static int	read_rt_file(t_list **line_list, const char *file_path)
{
	t_list	head;
	t_list	*cur;
	int		fd;
	int		gnl_ret;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (perror_rt("open"), FAILURE);
	cur = ft_memset(&head, 0, sizeof(t_list));
	while (cur)
	{
		gnl_ret = ft_get_next_line(fd, &line);
		if (gnl_ret == -1)
			return (perror_rt("read"), \
ft_lstclear(&head.next, free), close(fd), FAILURE);
		if (gnl_ret == -2)
			return (perror_rt("malloc"), \
ft_lstclear(&head.next, free), close(fd), FAILURE);
		cur->next = ft_lstnew(line);
		cur = cur->next;
	}
	if (!cur)
		return (perror("malloc"), \
ft_lstclear(&head.next, free), close(fd), FAILURE);
	*line_list = head.next;
	return (close(fd), SUCCESS);
}
