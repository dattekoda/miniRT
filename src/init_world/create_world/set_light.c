/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:27:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/18 13:08:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "validate_utils.h"
#include "world.h"
#include "libft.h"

static int	new_light_node(t_list **new_node, const char *line);
int			line_to_light(t_hitter **light, const char *line);

int	set_light(t_list **light_list, const t_list *line_list/*, t_point3 camera_p*/)
{
	t_list		*new_node;

	while (line_list)
	{
		if (match_identifier(line_list->content, &g_light_info) == SUCCESS)
		{
			// camera point をもとに line_list書き換え
			if (new_light_node(&new_node, line_list->content) == FAILURE)
			{
				ft_lstclear(light_list, clear_hitter);
				return (FAILURE);
			}
			ft_lstadd_back(light_list, new_node);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}

static int	new_light_node(t_list **new_node, const char *line)
{
	t_hitter	*new_light;

	if (line_to_light(&new_light, line) == FAILURE)
		return (FAILURE);
	*new_node = ft_lstnew(new_light);
	if (!*new_node)
	{
		new_light->clear(&new_light);
		return (FAILURE);
	}
	return (SUCCESS);
}
