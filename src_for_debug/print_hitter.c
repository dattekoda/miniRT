/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:02:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/20 19:30:30 by ikawamuk         ###   ########.fr       */
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
		printf("it is null\n");
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
	// printf("%u\n", hitter->type);
	printf("type:%s ", string_table[hitter->type]);
	print_vec3(hitter->aabb.centroid);
}

void	print_hitter_list(const t_list *list)
{
	printf("hitter list:\n");
	if (!list)
	{
		printf("list has no content\n");
		return ;
	}
	t_list	*cur = (t_list *)list;
	printf("print list:\n");
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
		printf("arr has no content\n");
		return ;
	}
	printf("print arr:\n");
	while (i < arr.size)
	{
		print_hitter(arr.arr[i]);
		i++;
	}
}

static void	print_tree_recursive(t_hitter *node);
void	print_tree(t_hitter *node)
{
	printf("print bvh:\n");
	if (!node)
	{
		printf("the tree has nothing.\n");
		return ;
	}
	print_tree_recursive(node);
}

static void	print_tree_recursive(t_hitter *node)
{
	if (!node)
		return ;
	print_hitter(node);
	if (node->type != TREE)
		return ;
	t_tree	*tree = (t_tree *)node;
	print_tree_recursive(tree->lhs);
	print_tree_recursive(tree->rhs);
}


