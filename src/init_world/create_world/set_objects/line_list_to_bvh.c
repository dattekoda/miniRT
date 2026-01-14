/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_bvh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:30:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 00:08:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "tree.h"
#include "libft.h"

void		clear_hitter_arr(t_hitter_arr arr);
int			line_list_to_object_arr(t_hitter_arr *hit_arr,
				const t_list *line_list, const t_element *object_table[]);

int	hit_arr_to_bvh(t_hitter **root,const t_hitter_arr hit_arr);

int	line_list_to_bvh(t_hitter **node, const t_list *line_list,
				const t_element *object_table[])
{
	t_hitter_arr	hit_arr;

	*node = NULL;
	if (line_list_to_object_arr(&hit_arr, line_list, object_table) == FAILURE)
		return (FAILURE);
	if (hit_arr_to_bvh(node, hit_arr) == FAILURE)
	{
		clear_hitter_arr(hit_arr);
		return (FAILURE);
	}
	free(hit_arr.arr);
	return (SUCCESS);
}
