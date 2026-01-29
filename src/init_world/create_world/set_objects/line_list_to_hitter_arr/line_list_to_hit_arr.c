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
#include "result.h"
#include <stdlib.h>

int			add_hitter_list(t_list **hitter_list, const char *line,
				const t_element *element);
static int	hitter_list_to_hitter_arr(t_list *hitter_list,
				t_hitter_arr *hit_arr);
static bool	match_objects(const char *line, const t_element *object_table[],
				size_t *idx);
static int	line_list_to_hitter_list(t_list **hitter_list,
				const t_list *line_list, const t_element *object_table[]);

int	line_list_to_hit_arr(t_hitter_arr *hit_arr, const t_list *line_list,
		const t_element *object_table[])
{
	t_list	*hitter_list;

	ft_bzero(hit_arr, sizeof(t_hitter_arr));
	hitter_list = NULL;
	if (line_list_to_hitter_list(&hitter_list, line_list,
			object_table) == FAILURE)
		return (FAILURE);
	if (hitter_list_to_hitter_arr(hitter_list, hit_arr) == FAILURE)
		return (ft_lstclear(&hitter_list, NULL), FAILURE);
	return (ft_lstclear(&hitter_list, NULL), SUCCESS);
}

static int	hitter_list_to_hitter_arr(t_list *hitter_list,
		t_hitter_arr *hit_arr)
{
	t_list	*curr;
	size_t	i;

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
@brief if matched object_table return SUCCESS, or return FAILURE
@param idx if set NULL, you can get appropriate return value
*/
static bool	match_objects(const char *line, const t_element *object_table[],
		size_t *idx)
{
	size_t	i;

	i = 0;
	while (object_table[i])
	{
		if (match_identifier(line, object_table[i]))
		{
			if (idx)
				*idx = i;
			return (true);
		}
		i++;
	}
	return (false);
}

/*
@brief not responsible for free(hitter_list)
*/
static int	line_list_to_hitter_list(t_list **hitter_list,
		const t_list *line_list, const t_element *object_table[])
{
	size_t	obj_idx;

	while (line_list)
	{
		if (match_objects(line_list->content, object_table, &obj_idx))
		{
			if (add_hitter_list(hitter_list, line_list->content,
					object_table[obj_idx]) == FAILURE)
				return (FAILURE);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}
