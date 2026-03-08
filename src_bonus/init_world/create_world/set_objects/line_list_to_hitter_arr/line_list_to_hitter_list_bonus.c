/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_hitter_list_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:57:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:31:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils_bonus.h"
#include "element_bonus.h"

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
	ssize_t	obj_idx;

	while (line_list)
	{
		obj_idx = search_object(line_list->content, object_table);
		if (obj_idx == -1)
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
