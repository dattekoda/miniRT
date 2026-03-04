/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_hitter_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:57:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/04 16:49:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "element.h"

int				add_hitter_list(t_list **hitter_list, const char *line,
					const t_element *element);

/*
@brief not responsible for free(hitter_list)
*/
int	line_list_to_hitter_list(t_list **hitter_list,
		const t_list *line_list, const t_element *object_table[])
{
	ssize_t	obj_idx;

	while (line_list)
	{
		obj_idx = search_object(line_list->content, object_table);
		if (obj_idx == -1)
		{
			line_list = line_list->next;
			continue ;
		}
		if (add_hitter_list(hitter_list, line_list->content,
				object_table[obj_idx]) == FAILURE)
			return (FAILURE);
		line_list = line_list->next;
	}
	return (SUCCESS);
}
