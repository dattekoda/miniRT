/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_line_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:53:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:23:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "init_world_utils.h"
#include "world.h"
#include "libft.h"
#include <stdlib.h>

static void	delete_light_line(t_list **line_list);

/*
@brief line_listを書き換える可能性があるため、失敗したらclearとNULL埋めをする
*/
int	preprocess_line_list(const t_world *world, t_list **line_list)
{
	if (world->option_flag & IS_PHONG)
		delete_light_line(line_list);
	return (SUCCESS);
}

static void	delete_light_line(t_list **line_list)
{
	t_list		dummy_head;
	t_list		*prev;
	t_list		*curr;

	dummy_head.next = *line_list;
	prev = &dummy_head;
	curr = prev->next;
	while (curr)
	{
		if (match_identifier(curr->content, &g_light_info) == SUCCESS)
		{
			prev->next = curr->next;
			ft_lstdelone(curr, free);
			curr = prev->next;
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
	*line_list = dummy_head.next;
}
