/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects_in_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:30:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/14 00:07:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "tree.h"
#include "libft.h"

t_hitter	**line_list_to_object_arr(const t_list *line_list, \
const t_element *object_table[]);
void		clear_hitter_arr(t_hitter **hitter_arr);

t_tree	*set_object_in_table(const t_list *line_list, \
const t_element *object_table[])
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
