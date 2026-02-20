/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:02:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/20 22:12:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "hitter.h"
#include "hitter_arr.h"
#include "libft.h"
#include "rt_debug.h"
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
	// fprintf(stderr, "%u\n", hitter->type);
	fprintf(stderr, "type:%s ", string_table[hitter->type]);
	print_vec3(hitter->aabb.centroid);
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

void	print_hitter_arr(t_hitter_arr arr)
{
	size_t	i = 0;

	if (arr.size == 0)
	{
		fprintf(stderr, "arr has no content\n");
		return ;
	}
	fprintf(stderr, "print arr:\n");
	while (i < arr.size)
	{
		print_hitter(arr.arr[i]);
		i++;
	}
}

static void	print_tree_recursive(t_hitter *node, int depth);
void	print_tree(t_hitter *node)
{
	fprintf(stderr, "print bvh:\n");
	if (!node)
	{
		fprintf(stderr, "the tree has nothing.\n");
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
	fprintf(stderr, "%*s", depth + 1, "");
	print_tree_recursive(tree->lhs, depth + 1);
	fprintf(stderr, "%*s", depth + 1, "");
	print_tree_recursive(tree->rhs, depth + 1);
}


