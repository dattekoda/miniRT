/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:02:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 20:27:32 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "hitter.h"
#include "hitter_arr.h"
#include "libft.h"
#include "rt_debug.h"
#include "material.h"
#include <stdio.h>

static void	print_tree_recursive(t_hitter *node, int depth);

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
	LIST,
	NOTHING
}	t_element_type;
*/

static const char	*g_type_table[] = {
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
	"LIST",
	"NOTHING",
	NULL
};

void	print_hitter(t_hitter *hitter)
{
	if (!hitter)
	{
		fprintf(stderr, "it is null\n");
		return ;
	}
	fprintf(stderr, "type:%s\t", g_type_table[hitter->type]);
	print_vec3(hitter->aabb.centroid);
	print_aabb(hitter->aabb);
	if (hitter->mat_ptr)
	{
		fprintf(stderr, "color: ");
		print_vec3(
			hitter->mat_ptr->texture_ptr->calc_texture_value(
				hitter->mat_ptr->texture_ptr,
				NULL));
	}
}

void	print_hitter_list(const t_list *list)
{
	fprintf(stderr, "hitter list:\n");
	if (!list)
	{
		fprintf(stderr, "list has no content\n");
		return ;
	}
	while (list)
	{
		print_hitter((t_hitter *)list->content);
		list = list->next;
	}
	printf("print hitter list done\n");
}

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
	const t_tree	*tree = (const t_tree *)node;

	if (!node)
		return ;
	print_hitter(node);
	if (node->type != TREE)
		return ;
	fprintf(stderr, "tree depth: %d\n", depth);
	fprintf(stderr, "lhs\t:");
	print_tree_recursive(tree->lhs, depth + 1);
	fprintf(stderr, "rhs\t:");
	print_tree_recursive(tree->rhs, depth + 1);
	fprintf(stderr, "\n");
}
