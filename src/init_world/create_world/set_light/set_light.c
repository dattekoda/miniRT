/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:52:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/07 19:57:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "vec_utils.h"
#include "world.h"
#include "rt_utils.h"
#include "rt_define.h"
#include "solid_texture.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

static int	new_light_node(t_list **new_list, const char *line,
				int option_flag);
int			preprocess_line_list(t_list *line_list, t_point3 camera_origin);
int			line_to_light(t_hitter **light, const char *line);

int	set_light(t_world *world, t_list *line_list, int option_flag)
{
	t_list	*new_node;

	if (preprocess_line_list(line_list, world->camera.origin) == FAILURE)
		return (FAILURE);
	while (line_list)
	{
		if (match_identifier(line_list->content, g_info_table[LIGHT]))
		{
			if (new_light_node
				(&new_node, line_list->content, option_flag) == FAILURE)
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

static int	new_light_node(t_list **new_list, const char *line, int option_flag)
{
	t_hitter		*new_light;
	t_solid_texture	*solid_ptr;

	if (line_to_light(&new_light, line) == FAILURE)
		return (FAILURE);
	if (!(option_flag & OPT_ARTIFICIAL))
	{
		solid_ptr = (t_solid_texture *)new_light->mat_ptr->texture_ptr;
		solid_ptr->color
			= scal_mul_vec3(solid_ptr->color, PATHTRACING_LIGHT_STRENGTH);
	}
	*new_list = ft_lstnew(new_light);
	if (!*new_list)
	{
		new_light->clear(&new_light);
		return (FAILURE);
	}
	return (SUCCESS);
}
