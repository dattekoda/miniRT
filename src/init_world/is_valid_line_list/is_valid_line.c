/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:35:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:39:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "libft.h"
#include "rt_utils.h"
#include "validate_utils.h"

bool		is_valid_element(char *line, const t_element *elem_info,
				const int option_flag);
static void	err_invalid_identifer(char *line);

bool	is_valid_line(char *line, const int option_flag)
{
	size_t	i;

	i = 0;
	while (g_info_table[i])
	{
		if (match_identifier(line, g_info_table[i]))
			return (is_valid_element(line, g_info_table[i], option_flag));
		i++;
	}
	return (err_invalid_identifer(line), false);
}

static void	err_invalid_identifer(char *line)
{
	t_line_reader	line_reader;

	line_reader = construct_line_reader(line);
	while (!ft_strchr(" \t", lr_getc(&line_reader)))
		(line_reader.idx)++;
	(line_reader.idx)--;
	err_point_out(&line_reader);
	err_rt("invalid identifier");
	return ;
}
