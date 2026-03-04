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
#include "rt_utils.h"
#include "result.h"
#include <stdlib.h>

int				line_list_to_hitter_list(
					t_list **list,
					const t_list *line_list,
					const t_element *object_table[]);
static int		hitter_list_to_hitter_arr(
					const t_list *list,
					t_hitter_arr *hit_arr);

int	line_list_to_hit_arr(
			t_hitter_arr *hit_arr,
			const t_list *line_list,
			const t_element *object_table[])
{
	t_list	*head;

	ft_bzero(hit_arr, sizeof(t_hitter_arr));
	head = NULL;
	if (line_list_to_hitter_list(&head, line_list,
			object_table) == FAILURE)
	{
		ft_lstclear(&head, clear_free_hitter);
		return (FAILURE);
	}
	if (hitter_list_to_hitter_arr(head, hit_arr) == FAILURE)
	{
		ft_lstclear(&head, clear_free_hitter);
		return (FAILURE);
	}
	ft_lstclear(&head, NULL);
	return (SUCCESS);
}

static int	hitter_list_to_hitter_arr(
		const t_list *list,
		t_hitter_arr *hit_arr)
{
	size_t	i;

	if (!list)
		return (SUCCESS);
	hit_arr->size = (size_t)ft_lstsize((t_list *)list);
	hit_arr->arr = ft_calloc(hit_arr->size, sizeof(t_hitter *));
	if (!hit_arr->arr)
		return (FAILURE);
	i = 0;
	while (list)
	{
		hit_arr->arr[i++] = list->content;
		list = list->next;
	}
	return (SUCCESS);
}
