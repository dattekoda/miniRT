/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_object_arr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:59:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 13:44:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "hitter_arr.h"
#include "libft.h"

int	line_to_object(t_hitter **hitter, 
	const char *line, const t_element *object_table[]);
static size_t	count_objects(const t_list *line_list, 
	const t_element *object_table[]);
void			clear_hitter_arr(t_hitter_arr hit_arr);

int	line_list_to_object_arr(t_hitter_arr *hit_arr, const t_list *line_list, \
const t_element *object_table[])
{
	size_t		i;

	ft_bzero(hit_arr, sizeof(t_hitter_arr));
	hit_arr->size= count_objects(line_list, object_table);
	if (hit_arr->size == 0)
		return (SUCCESS);
	hit_arr->arr = ft_calloc(hit_arr->size, sizeof(t_hitter *));
	if (!hit_arr->arr)
		return (FAILURE);
	i = 0;
	while (line_list)
	{
		if (line_to_object(
			&hit_arr->arr[i], line_list->content, object_table) == SUCCESS)
			return (clear_hitter_arr(*hit_arr), NULL);
		i++;
		line_list = line_list->next;
	}
	return (SUCCESS);
}

int	line_to_object(t_hitter **hitter, const char *line, const t_element *object_table[])
{
	size_t	i;

	i = 0;
	while (object_table[i])
	{
		if (match_identifier(line, object_table[i]) == SUCCESS)
			return (object_table[i]->line_to_hitter(hitter, line));
		i++;
	}
	return (NULL);
}

void	clear_hitter_arr(t_hitter_arr hit_arr)
{
	size_t	i;

	i = 0;
	while (i < hit_arr.size && hit_arr.arr[i])
	{
		hit_arr.arr[i]->clear(hit_arr.arr[i]);
		i++;
	}
	free(hit_arr.arr);
}

static size_t	count_objects(const t_list *line_list, \
const t_element *object_table[])
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
