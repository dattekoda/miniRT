/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:16:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 19:07:19 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "validate_utils.h"
#include "world.h"
#include "rt_utils.h"
#include "libft.h"
#include <stdlib.h>

static void	delete_light_line(t_list **line_list);
int			finite_line_list_to_bvh(t_hitter **node, const t_list *line_list);
int			infinite_line_list_to_hitter_list(
				t_hitter **node,
				const t_list *line_list);
t_hitter	*generate_tree(t_hitter *lhs, t_hitter *rhs);
void		clear_tree(void *s);

int	set_objects(t_world *world, t_list *line_list, int option_flag)
{
	t_hitter	*rhs;
	t_hitter	*lhs;

	if (option_flag & OPT_ARTIFICIAL)
		delete_light_line(&line_list);
	if (infinite_line_list_to_hitter_list(&rhs, line_list) == FAILURE)
		return (FAILURE);
	if (finite_line_list_to_bvh(&lhs, line_list) == FAILURE)
	{
		clear_tree(rhs);
		return (FAILURE);
	}
	world->object_tree = generate_tree(lhs, rhs);
	if (!world->object_tree && (lhs || rhs))
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
		if (match_identifier(curr->content, g_element_table[LIGHT]))
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
