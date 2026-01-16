/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:16:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 16:38:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "element.h"
#include "world.h"
#include "libft.h"
#include <stdlib.h>

int			preprocess_line_list(const t_world *world, t_list **line_list);
int			line_list_to_bvh(t_hitter **node, const t_list *line_list, 
			const t_element *object_table[]);
t_hitter	*gen_tree(t_hitter *lhs, t_hitter *rhs);
void		clear_tree(void *s);

int	set_objects(t_world *world, t_list *line_list)
{
	t_hitter	*rhs;
	t_hitter	*lhs;

	// if (preprocess_line_list(world, &line_list) == FAILURE)
	// 	return (FAILURE);
	if (line_list_to_bvh(&rhs, line_list, g_infinite_table) == FAILURE)
		return (FAILURE);
	if (line_list_to_bvh(&lhs, line_list, g_finite_table) == FAILURE)
	{
		clear_tree(rhs);
		return (FAILURE);
	}
	world->object_tree = gen_tree(lhs, rhs);
	if (!world->object_tree)
		return (FAILURE);
	return (SUCCESS);
}
