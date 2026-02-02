/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:42:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/02 18:19:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_READER_H
# define LINE_READER_H

# include <stddef.h>

typedef struct s_line_reader
{
	char	*line;
	size_t	idx;
}	t_line_reader;

t_line_reader	construct_line_reader(char *line);
char			lr_getc(const t_line_reader *line_reader);

#endif