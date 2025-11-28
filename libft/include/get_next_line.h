/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:55:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/12 14:34:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# if BUFFER_SIZE < 0
#  error "BUFFER_SIZE must be positive."
# endif

# define HASH_SIZE 1009

typedef struct s_save
{
	char	*data;
	size_t	buf_size;
	size_t	str_len;
}	t_save;

typedef struct s_list
{
	int				fd;
	t_save			save;
	struct s_list	*next;
}	t_list;

// get_next_line
char	*get_next_line(int fd);
// utils
t_list	*alloc_fd_node(int fd, t_list	*table[]);
void	free_fd_node(int fd, t_list	*table[]);
bool	has_new_line(char *str);
bool	expand_save(t_save *save, ssize_t rd_size);

#endif