/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_bvh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:13:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 21:47:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "hitter_arr.h"
#include "libft.h"
#include <stdlib.h>

static void		clear_hitter_arr(t_hitter_arr arr);
int			line_list_to_hit_arr(t_hitter_arr *hit_arr,
				const t_list *line_list, const t_element *object_table[]);
int			hit_arr_to_bvh(t_hitter **root, const t_hitter_arr hit_arr);

int	line_list_to_bvh(t_hitter **node, const t_list *line_list,
			const t_element *object_table[])
{
	t_hitter_arr	hit_arr;

	*node = NULL;
	if (line_list_to_hit_arr(&hit_arr, line_list, object_table) == FAILURE)
		return (FAILURE);
	if (hit_arr_to_bvh(node, hit_arr) == FAILURE)
	{
		clear_hitter_arr(hit_arr);
		return (FAILURE);
	}
	free(hit_arr.arr);
	return (SUCCESS);
}

static void		clear_hitter_arr(t_hitter_arr arr)
{
	size_t		i;

	i = 0;
	while (i < arr.size)
	{
		arr.arr[i]->clear(arr.arr[i]);
		i++;
	}
	free(arr.arr);
}
