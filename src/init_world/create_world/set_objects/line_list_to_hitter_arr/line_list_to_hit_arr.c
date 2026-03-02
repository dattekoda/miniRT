/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_hit_arr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:13:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 14:14:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "element.h"
#include "hitter_arr.h"
#include "init_world_define.h"
#include "init_world_utils.h"
#include "libft.h"
#include "rt_utils.h"
#include "result.h"
#include <stdlib.h>

int				add_hitter_list(t_list **hitter_list, const char *line,
					const t_element *element);
static int		hitter_list_to_hitter_arr(t_list *hitter_list,
				t_hitter_arr *hit_arr);
static ssize_t	search_objects(const char *line, const t_element *object_table[]);
static int		line_list_to_hitter_list(t_list **hitter_list,
					const t_list *line_list, const t_element *object_table[]);


#include "rt_debug.h"
int	line_list_to_hit_arr(
			t_hitter_arr *hit_arr,
			const t_list *line_list,
			const t_element *object_table[])
{
	t_list	*hitter_list;

	ft_bzero(hit_arr, sizeof(t_hitter_arr));
	hitter_list = NULL;
	if (line_list_to_hitter_list(&hitter_list, line_list,
			object_table) == FAILURE)
	{
		ft_lstclear(&hitter_list, clear_free_hitter);
		return (FAILURE);
	}
	if (hitter_list_to_hitter_arr(hitter_list, hit_arr) == FAILURE)
	{
		ft_lstclear(&hitter_list, clear_free_hitter);
		return (FAILURE);
	}
	
	ft_lstclear(&hitter_list, NULL);
	return (SUCCESS);
}

static int	hitter_list_to_hitter_arr(t_list *hitter_list,
		t_hitter_arr *hit_arr)
{
	t_list	*curr;
	size_t	i;

	if (!hitter_list)
		return (SUCCESS);
	hit_arr->size = (size_t)ft_lstsize(hitter_list);
	hit_arr->arr = ft_calloc(hit_arr->size, sizeof(t_hitter *));
	if (!hit_arr->arr)
		return (FAILURE);
	curr = hitter_list;
	i = 0;
	while (curr)
	{
		hit_arr->arr[i++] = curr->content;
		curr = curr->next;
	}
	return (SUCCESS);
}

/*
@brief if line is one member of object_table
*/
static ssize_t	search_objects(const char *line, const t_element *object_table[])
{
	size_t	idx;

	idx = 0;
	while (object_table[idx])
	{
		if (match_identifier(line, object_table[idx]))
			return (idx);
		idx++;
	}
	return (-1);
}

/*
@brief not responsible for free(hitter_list)
*/
static int	line_list_to_hitter_list(t_list **hitter_list,
		const t_list *line_list, const t_element *object_table[])
{
	ssize_t	obj_idx;

	while (line_list)
	{
		obj_idx = search_objects(line_list->content, object_table);
		if (obj_idx == -1)
		{
			line_list = line_list->next;
			continue ;
		}
		if (add_hitter_list(hitter_list, line_list->content,
				object_table[obj_idx]) == FAILURE)
			return (FAILURE);
		line_list = line_list->next;
	}
	return (SUCCESS);
}
