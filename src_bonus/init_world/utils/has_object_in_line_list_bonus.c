/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_object_in_line_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:23:49 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_bonus.h"
#include <sys/types.h>

ssize_t	search_object(const char *line, const t_element *object_table[]);

bool	has_object_in_line_list(
		const t_list *line_list,
		const t_element *object_table[])
{
	t_element_type	idx;

	while (line_list)
	{
		idx = search_object(line_list->content, object_table);
		if (idx != INVALID_ELEM)
			return (true);
		line_list = line_list->next;
	}
	return (false);
}
