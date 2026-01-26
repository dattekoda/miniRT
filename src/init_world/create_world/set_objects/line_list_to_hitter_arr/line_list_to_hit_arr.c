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

#include "init_world_utils.h"
#include "init_world_define.h"
#include "element.h"
#include "hitter_arr.h"
#include "libft.h"
#include "result.h"
#include "element.h"
#include "hitter_arr.h"
#include "cylinder.h"
#include <stdlib.h>

static int	add_hitter_list(t_list **hitter_list, const char *line, 
		const t_element *element);
static int	line_list_to_hitter_list
	(t_list **hitter_list, const t_list *line_list, 
		const t_element *object_table[]);
static int	match_objects(const char *line, const t_element *object_table[], 
		size_t *idx);
static int	add_sub_hitters(t_list **hitter_list, t_hitter *hitter_tmp);
static bool	has_subhitter(const char *line);
int			add_cylinder_disk(t_list **hitter_list, t_cylinder *cylinder);

int	line_list_to_hit_arr(t_hitter_arr *hit_arr, const t_list *line_list, \
	const t_element *object_table[])
{
	size_t	arr_idx;
	t_list	*hitter_list;
	t_list	*curr;

	ft_bzero(hit_arr, sizeof(t_hitter_arr));
	hitter_list = NULL;
	if (line_list_to_hitter_list(&hitter_list, line_list, object_table) 
		== FAILURE)
		return (ft_lstclear(&hitter_list, free), FAILURE);
	hit_arr->size = (size_t)ft_lstsize(hitter_list);
	hit_arr->arr = ft_calloc(hit_arr->size, sizeof(t_hitter *));
	if (!hit_arr->arr)
		return (ft_lstclear(&hitter_list, free), FAILURE);
	curr = hitter_list;
	arr_idx = 0;
	while (curr)
	{
		hit_arr->arr[arr_idx++] = curr->content;
		curr = curr->next;
	}
	ft_lstclear(&hitter_list, NULL);
	return (SUCCESS);
}

/*
@brief if matched object_table return SUCCESS, or return FAILURE
@param idx if set NULL, you can get appropriate return value
*/
static int	match_objects(const char *line,
	const t_element *object_table[], size_t *idx)
{
	size_t	i;

	i = 0;
	while (object_table[i])
	{
		if (match_identifier(line, object_table[i]))
		{
			if (idx)
				*idx = i;
			return (SUCCESS);
		}
		i++;
	}
	return (FAILURE);
}

/*
@brief not responsible for free(hitter_list)
*/
static int	line_list_to_hitter_list
	(t_list **hitter_list, const t_list *line_list, 
		const t_element *object_table[])
{
	size_t		obj_idx;

	while (line_list)
	{
		if (match_objects(line_list->content, object_table, &obj_idx) == SUCCESS)
		{
			if (add_hitter_list(hitter_list, line_list->content, object_table[obj_idx]) == FAILURE)
				return (FAILURE);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}

static int	add_hitter_list(t_list **hitter_list, const char *line, const t_element *element)
{
	t_list		*list_tmp;
	t_hitter	*hitter_tmp;

	if (element->line_to_hitter(&hitter_tmp, line) == FAILURE)
		return (FAILURE);
	list_tmp = ft_lstnew(hitter_tmp);
	if (!list_tmp)
		return (hitter_tmp->clear(hitter_tmp), FAILURE);
	ft_lstadd_back(hitter_list, list_tmp);
	if (has_subhitter(line) == SUCCESS)
	{
		if (add_sub_hitters(hitter_list, list_tmp->content) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static bool	has_subhitter(const char *line)
{
	return (match_identifier(line, &g_cylinder_info));
}

static int	add_sub_hitters(t_list **hitter_list, t_hitter *hitter_tmp)
{
	if (add_cylinder_disk(hitter_list, (t_cylinder *)hitter_tmp) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
