/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_line_reader.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:47:16 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/02 19:13:32 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_reader.h"
#include "libft.h"

t_line_reader	construct_line_reader(char *line)
{
	t_line_reader	line_reader;

	ft_bzero(&line_reader, sizeof(t_line_reader));
	line_reader.line = line;
	return (line_reader);
}
