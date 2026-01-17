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

#include "element.h"
#include "hitter_arr.h"
#include "libft.h"
#include "init_world_define.h"
#include "init_world_uttils.h"
#include "result.h"
#include "element.h"
#include "hitter_arr.h"

static size_t	count_objects(
					const t_list *line_list, const t_element *object_table[]);
void			clear_hitter_arr(t_hitter_arr hit_arr);
int				match_objects(const char *line,
					const t_element *object_table[], size_t *idx);

int	line_list_to_hit_arr(t_hitter_arr *hit_arr, const t_list *line_list, \
const t_element *object_table[])
{
	size_t	obj_idx;
	size_t	arr_idx;
	t_list	*hitter_list;

	ft_bzero(hit_arr, sizeof(t_hitter_arr));
	if (line_list_to_hitter_list(&hitter_list, line_list, object_table) 
		== FAILURE)
		return (ft_lstclear(hitter_list, free), FAILURE);

	hit_arr->size = ft_lstsize(&hitter_list);

	hit_arr->size = count_objects(line_list, object_table);
	if (hit_arr->size == 0)
		return (SUCCESS);
	hit_arr->arr = ft_calloc(hit_arr->size, sizeof(t_hitter *));
	if (!hit_arr->arr)
		return (FAILURE);
	arr_idx = 0;
	while (line_list)
	{
		if (match_objects(line_list->content,
				object_table, &obj_idx) == SUCCESS)
		{
			if (object_table[obj_idx]->line_to_hitter(
					&hit_arr->arr[arr_idx], line_list->content) == FAILURE)
				return (clear_hitter_arr(*hit_arr), FAILURE);
			arr_idx++;
		}
		line_list = line_list->next;
	}

	ft_lstclear(&hitter_list, NULL);
	return (SUCCESS);
}

void	clear_hitter_arr(t_hitter_arr hit_arr)
{
	size_t	i;

	i = 0;
	while (i < hit_arr.size)
	{
		if (hit_arr.arr[i])
			hit_arr.arr[i]->clear(hit_arr.arr[i]);
		i++;
	}
	free(hit_arr.arr);
}

static size_t	count_objects(const t_list *line_list, \
const t_element *object_table[])
{
	size_t	count;
	size_t	idx;

	count = 0;
	while (line_list)
	{
		if (match_objects(line_list->content, object_table, &idx) == SUCCESS)
			count += object_table[idx]->primitive_num;
		line_list = line_list->next;
	}
	return (count);
}

/*
@brief if matched object_table return SUCCESS, or return FAILURE
@param idx if set NULL, you can get appropriate return value
*/
int	match_objects(const char *line,
	const t_element *object_table[], size_t *idx)
{
	size_t	i;

	i = 0;
	while (object_table[i])
	{
		if (match_identifier(line, object_table[i]) == SUCCESS)
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
int	line_list_to_hitter_list(t_list **hitter_list, const t_list *line_list, 
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

int	add_hitter_list(t_list **hitter_list, const char *line, const t_element *element)
{
	t_list		*list_tmp;
	t_hitter	*hitter_tmp;

	if (element->line_to_hitter(&hitter_tmp, line) == FAILURE)
		return (FAILURE);
	list_tmp = ft_lstnew(hitter_tmp);
	if (!list_tmp)
		return (hitter_tmp->clear(hitter_tmp), FAILURE);
	ft_lstadd_back(hitter_list, list_tmp);

	if (match_identifier(line, g_cylinder_info) == SUCCESS)
	{
		if (add_cylinder_disk(hitter_list, (t_cylinder)*hitter_tmp) == FAILURE)
			return (FAILURE);
	}

	return (SUCCESS);
}
