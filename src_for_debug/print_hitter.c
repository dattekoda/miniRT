/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:02:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/17 07:17:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"
#include "hitter_arr.h"
#include "libft.h"
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
	printf("type:%s x:%f\n", string_table[hitter->type], hitter->aabb.centroid.e[0]);
}

void	print_hitter_list(const t_list *list)
{
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
