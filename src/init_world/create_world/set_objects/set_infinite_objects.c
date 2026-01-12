/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_infinite_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:30:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 14:36:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "tree.h"
#include "libft.h"

int	match_identifier(const char *line, const t_element_info *info);
int	match_infinite_object(const char *line);


t_tree	*set_infinite_objects(const t_list *line_list)
{
	t_hitter	**hitter_arr;
	size_t		arr_size;

	arr_size = count_infinite_object(line_list);
	hitter_arr = ft_calloc(arr_size, sizeof(t_hitter *));
	if (!hitter_arr)
		return (NULL);
	
}

size_t	count_infinite_object(const t_list *line_list)
{
	size_t	count;

	count = 0;
	while (line_list)
	{
		if (is_infinite_object(line_list->content))
			count++;
		line_list = line_list->next;
	}
	return (count);
}

int	match_infinite_object(const char *line)
{
	size_t	i;

	i = 0;
	while (g_infinite_table[i])
	{
		if (match_identifier(line, g_infinite_table[i]) == SUCCESS)
			return (SUCCESS);
	}
	return (FAILURE);
}
