/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_identifer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:37:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 19:32:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

bool	match_identifier(const char *line, const t_element *info)
{
	if (ft_strncmp(line, info->id, info->id_len))
		return (false);
	if (ft_strchr(" \t", line[info->id_len]) == NULL)
		return (false);
	return (true);
}
