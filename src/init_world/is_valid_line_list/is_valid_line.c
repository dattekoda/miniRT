/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:35:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 03:19:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "init_world_utils.h"
#include "rt_utils.h"
#include "libft.h"

bool		is_valid_element
	(char *line, const t_element *elem_info, const int option_flag);
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
	size_t	identifier_idx;

	identifier_idx = 0;
	while (!ft_strchr(" \t", line[identifier_idx]))
		identifier_idx++;
	err_point_out(line, identifier_idx - 1);
	err_rt("invalid identifier");
	return ;
}
