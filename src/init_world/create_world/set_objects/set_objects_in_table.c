/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects_in_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:30:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 21:51:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "tree.h"
#include "libft.h"

int	match_infinite_object(const char *line);

t_tree	*set_object_in_table(const t_list *line_list, const t_element *object_table[])
{
	t_tree		*root;
	t_hitter	**hitter_arr;

	hitter_arr = line_list_to_object_arr(line_list, object_table);
	if (!hitter_arr)
		return (NULL);
	root = gen_bvh(hitter_arr);
	if (!root)
	{
		clear_hitter_arr(hitter_arr);
		return (NULL);
	}
	free(hitter_arr);
	return (root);
}

t_hitter	**line_list_to_object_arr(const t_list *line_list, const t_element *object_table[])
{
	t_hitter	**hitter_arr;
	size_t		arr_size;
	size_t		i;

	arr_size = count_object(line_list, object_table);
	hitter_arr = ft_calloc(arr_size + 1, sizeof(t_hitter *));
	if (!hitter_arr)
		return (NULL);
	i = 0;
	while (line_list)
	{
		if (match_objects(line_list->content, object_table) == SUCCESS)
		{
			hitter_arr[i] = line_to_object(line_list->content);
			if (!hitter_arr[i])
				return (clear_hitter_arr(hitter_arr), NULL);
			i++;
		}
		line_list = line_list->next;
	}
	return (hitter_arr);
}

t_hitter	*line_to_object(const char *line)
{
	size_t	i;

	i = 0;
	while (g_info_table[i])
	{
		if (match_identifier(line, g_info_table[i]) == SUCCESS)
			return (g_info_table[i]->line_to_hitter(line));
		i++;
	}
	return (NULL);
}

/*
@param NULLポインタ終端であるt_hitterのポインタ型の配列
*/
static void	clear_hitter_arr(t_hitter **hitter_arr)
{
	size_t	i;

	i = 0;
	while (hitter_arr[i])
	{
		hitter_arr[i]->clear(&hitter_arr[i]);
		i++;
	}
	free(*hitter_arr);
	*hitter_arr = NULL;
}

size_t	count_objects(const t_list *line_list, const t_element *object_table[])
{
	size_t	count;

	count = 0;
	while (line_list)
	{
		if (match_objects(line_list->content, object_table) == SUCCESS)
			count++;
		line_list = line_list->next;
	}
	return (count);
}

int	match_objects(const char *line, const t_element *object_table[])
{
	size_t	i;

	i = 0;
	while (object_table[i])
	{
		if (match_identifier(line, object_table[i++]) == SUCCESS)
			return (SUCCESS);
	}
	return (FAILURE);
}
