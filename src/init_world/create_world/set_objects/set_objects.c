/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:17:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 14:34:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "world.h"
#include "libft.h"

t_tree	*set_infinite_objects(const t_list *line_list);
t_tree	*set_finite_objects(const t_list *line_list);

int	set_objects(t_world *world, const t_list *line_list)
{
	world->object_tree->rhs = set_infinite_objects(line_list);
	if (!world->object_tree->rhs)
		return (FAILURE);
	world->object_tree->lhs = set_finite_objects(line_list);
	if (!world->object_tree->lhs)
	{
		clear_node(world->object_tree->rhs);
		return (FAILURE);
	}
	world->object_tree->hitter = construct_tree_hitter(&world->object_tree);
	return (SUCCESS);
}
