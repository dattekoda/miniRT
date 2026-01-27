/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:52:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/27 19:22:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "vec_utils.h"
#include "world.h"
#include "rt_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

static int	new_light_node(t_list **new_list, const char *line, bool is_phong);
int			preprocess_line_list(t_list *line_list, t_point3 camera_origin);
int			line_to_light(t_hitter **light, const char *line, bool is_phong);

int	set_light(t_world *world, t_list *line_list)
{
	t_list	*new_node;

	if (preprocess_line_list(line_list, world->camera.origin) == FAILURE)
		return (FAILURE);
	while (line_list)
	{
		if (match_identifier(line_list->content, &g_light_info))
		{
			if (new_light_node
				(&new_node, line_list->content, world) == FAILURE)
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

static int	new_light_node(t_list **new_list, const char *line, bool is_phong)
{
	t_hitter	*new_light;

	if (line_to_light(&new_light, line, is_phong) == FAILURE)
		return (FAILURE);
	*new_list = ft_lstnew(new_light);
	if (!*new_list)
	{
		new_light->clear(&new_light);
		return (FAILURE);
	}
	return (SUCCESS);
}
