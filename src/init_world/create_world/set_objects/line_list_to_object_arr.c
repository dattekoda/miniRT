/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_object_arr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:59:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 21:59:02 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"
#include "libft.h"
#include "init_world_define.h"
#include "init_world_utils.h"
#include "result.h"
#include "element.h"
#include "hitter_arr.h"

static size_t	count_objects(
					const t_list *line_list, const t_element *object_table[]);
void			clear_hitter_arr(t_hitter_arr hit_arr);
int				match_objects(const char *line,
					const t_element *object_table[], size_t *idx);

int	line_list_to_object_arr(t_hitter_arr *hit_arr, const t_list *line_list, \
const t_element *object_table[])
{
	size_t	obj_idx;
	size_t	arr_idx;

	ft_bzero(hit_arr, sizeof(t_hitter_arr));
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
			arr_idx += object_table[obj_idx]->primitive_num;
		}
		line_list = line_list->next;
	}
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
