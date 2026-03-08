/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:52:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result_bonus.h"
#include "init_world_utils_bonus.h"
#include "validate_utils_bonus.h"
#include "vec_utils_bonus.h"
#include "world_bonus.h"
#include "rt_utils_bonus.h"
#include "rt_define_bonus.h"
#include "solid_texture_bonus.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

static int	new_light_node(t_list **new_list, const char *line);
int			preprocess_line_list(
				t_list *line_list, t_point3 camera_origin, int option_flag);
int			line_to_light(t_hitter **light, const char *line);

int	set_light(t_world *world, t_list *line_list, int option_flag)
{
	t_list	*new_node;

	if (preprocess_line_list(
			line_list, world->camera.origin, option_flag) == FAILURE)
		return (FAILURE);
	while (line_list)
	{
		if (match_identifier(line_list->content, g_element_table[LIGHT]))
		{
			if (new_light_node(&new_node, line_list->content) == FAILURE)
			{
				ft_lstclear(&world->light_list, clear_free_hitter);
				return (FAILURE);
			}
			ft_lstadd_back(&world->light_list, new_node);
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
		clear_free_hitter(new_light);
		return (FAILURE);
	}
	return (SUCCESS);
}
