/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:27:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:03:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "validate_utils.h"
#include "world.h"
#include "libft.h"

int		line_to_light(t_hitter **light, const char *line);
void	clear_hitter(void *content);

int	set_light(t_world *world, const t_list *line_list)
{
	t_hitter	*new_light;
	t_list		*new_node;

	while (line_list)
	{
		if (match_identifier(line_list->content, &g_light_info) == SUCCESS)
		{
			if (line_to_light(&new_light, line_list->content) == FAILURE)
			{
				ft_lstclear(&world->light_list, clear_hitter);
				return (FAILURE);
			}
			new_node = ft_lstnew(new_light);
			if (!new_node)
			{
				ft_lstclear(&world->light_list, clear_hitter);
				return (FAILURE);
			}
			ft_lstadd_back(&world->light_list, new_node);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}
