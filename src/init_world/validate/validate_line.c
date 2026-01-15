/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:35:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 12:59:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "init_world_utils.h"
#include "libft.h"

int			validate_element(char *line, const t_element *elem_info);
static int	validate_invalid_id(char *line);

int	validate_line(char *line)
{
	size_t	i;

	i = 0;
	while (g_info_table[i])
	{
		if (match_identifier(line, g_info_table[i]) == SUCCESS)
			return (validate_element(line, g_info_table[i]));
		i++;
	}
	return (validate_invalid_id(line));
}

static int	validate_invalid_id(char *line)
{
	size_t	identifier_idx;

	identifier_idx = 0;
	while (!ft_strchr(" \t", line[identifier_idx]))
		identifier_idx++;
	err_point_out(line, identifier_idx - 1);
	err_rt("invalid identifier");
	return (FAILURE);
}
