/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_identifer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:37:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 12:39:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "result.h"

int	match_identifier(const char *line, const t_element *info)
{
	if (ft_strncmp(line, info->id, info->id_len))
		return (FAILURE);
	if (ft_strchr(" \t", line[info->id_len]) == NULL)
		return (FAILURE);
	return (SUCCESS);
}
