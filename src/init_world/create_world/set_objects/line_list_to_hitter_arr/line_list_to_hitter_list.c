/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_hitter_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:57:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 17:38:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "element.h"

int				add_hitter_list(t_list **head, const char *line,
					const t_element *element);

/*
@brief not responsible for free(head)
*/
int	line_list_to_hitter_list(
		t_list **head,
		const t_list *line_list,
		const t_element *object_table[])
{
	t_element_type	obj_idx;

	while (line_list)
	{
		obj_idx = search_object(line_list->content, object_table);
		if (obj_idx == INVALID_ELEM)
		{
			line_list = line_list->next;
			continue ;
		}
		if (add_hitter_list(head, line_list->content,
				object_table[obj_idx]) == FAILURE)
			return (FAILURE);
		line_list = line_list->next;
	}
	return (SUCCESS);
}
