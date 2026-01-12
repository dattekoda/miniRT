/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:17:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 21:43:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "world.h"
#include "libft.h"
#include <stdlib.h>

static void	delete_light_line(t_list **line_list);
t_tree		*set_object_in_table(const t_list *line_list, const t_element *object_table[]);

int	set_objects(t_world *world, t_list *line_list)
{
	if (world->option_flag & IS_PHONG)
		delete_light_line(line_list);
	world->object_tree->rhs = set_object_in_table(line_list, g_infinite_table);
	if (!world->object_tree->rhs)
		return (FAILURE);
	
	world->object_tree->lhs = set_object_in_table(line_list, g_finite_table);
	if (!world->object_tree->lhs)
	{
		clear_node(world->object_tree->rhs);
		return (FAILURE);
	}
	world->object_tree->hitter = construct_tree_hitter(&world->object_tree);
	return (SUCCESS);
}

static void	delete_light_line(t_list **line_list)
{
	t_list		dummy_head;
	t_list		*prev;
	t_list		*curr;

	dummy_head.next = *line_list;
	prev = &dummy_head;
	curr = prev->next;
	while (curr)
	{
		if (match_identifier(curr->content, &g_light_info) == SUCCESS)
		{
			prev->next = curr->next;
			ft_lstdelone(curr, free);
			curr = prev->next;
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
	*line_list = dummy_head.next;
}


