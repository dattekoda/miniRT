/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_object_in_line_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:23:49 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 18:50:14 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

ssize_t	search_object(const char *line, const t_element *object_table[]);

bool	has_object_in_line_list(
		const t_list *line_list,
		const t_element *object_table[])
{
	ssize_t	obj_idx;

	while (line_list)
	{
		obj_idx = search_object(line_list->content, object_table);
		if (obj_idx != -1)
			return (true);
		line_list = line_list->next;
	}
	return (false);
}
