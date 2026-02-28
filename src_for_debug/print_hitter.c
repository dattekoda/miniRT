/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:02:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 18:33:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "hitter.h"
#include "hitter_arr.h"
#include "libft.h"
#include "rt_debug.h"
#include "material.h"
#include <stdio.h>

/*

typedef enum e_element_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	DISK,
	CONE,
	TRIANGLE,
	TREE,
	NOTHING
}	t_element_type;
*/

void	print_hitter(t_hitter *hitter)
{
	if (!hitter)
	{
		fprintf(stderr, "it is null\n");
		return ;
	}
	static const char *string_table[] = {
		"AMBIENT",
		"CAMERA",
		"LIGHT",
		"SPHERE",
		"PLANE",
		"CYLINDER",
		"DISK",
		"CONE",
		"TRIANGLE",
		"TREE",
		"NOTHING"
	};
	fprintf(stderr, "type:%s\t", string_table[hitter->type]);
	print_vec3(hitter->aabb.centroid);
	// print_aabb(hitter->aabb);
	// if (hitter->mat_ptr)
	// {
	// 	fprintf(stderr, "color: ");
	// 	print_vec3(hitter->mat_ptr->texture_ptr->calc_texture_value(hitter->mat_ptr->texture_ptr, NULL));
	// }
}

void	print_hitter_list(const t_list *list)
{
	fprintf(stderr, "hitter list:\n");
	if (!list)
	{
		fprintf(stderr, "list has no content\n");
		return ;
	}
	t_list	*cur = (t_list *)list;
	while (cur)
	{
		t_hitter *hitter = (t_hitter *)cur->content;
		print_hitter(hitter);
		cur = cur->next;
	}
}

static void	print_tree_recursive(t_hitter *node, int depth);
void	print_tree(t_hitter *node)
{
	fprintf(stderr, "\n------ print tree ------\n");
	if (!node)
	{
		fprintf(stderr, "tree has nothing.\n");
		return ;
	}
	print_tree_recursive(node, 0);
}

static void	print_tree_recursive(t_hitter *node, int depth)
{
	if (!node)
		return ;
	print_hitter(node);
	if (node->type != TREE)
		return ;
	t_tree	*tree = (t_tree *)node;
	fprintf(stderr, "depth: %d\n", depth);
	fprintf(stderr, "lhs\t:");
	print_tree_recursive(tree->lhs, depth + 1);
	fprintf(stderr, "rhs\t:");
	print_tree_recursive(tree->rhs, depth + 1);
}


