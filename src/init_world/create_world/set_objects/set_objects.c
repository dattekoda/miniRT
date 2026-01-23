/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:16:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/22 16:25:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "element.h"
#include "world.h"
#include "libft.h"
#include <stdlib.h>

static void	delete_light_line(t_list **line_list);
int			line_list_to_bvh(t_hitter **node, const t_list *line_list,
				const t_element *object_table[]);
t_hitter	*generate_tree(t_hitter *lhs, t_hitter *rhs);
void		clear_tree(void *s);

int	set_objects(t_world *world, t_list *line_list)
{
	t_hitter	*rhs;
	t_hitter	*lhs;

	if (world->option_flag & IS_PHONG)
		delete_light_line(&line_list);
	if (line_list_to_bvh(&rhs, line_list, g_infinite_table) == FAILURE)
		return (FAILURE);
	if (line_list_to_bvh(&lhs, line_list, g_finite_table) == FAILURE)
	{
		clear_tree(rhs);
		return (FAILURE);
	}
	world->object_tree = generate_tree(lhs, rhs);
	if (!world->object_tree)
		return (FAILURE);
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
		if (match_identifier(curr->content, &g_light_info))
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
