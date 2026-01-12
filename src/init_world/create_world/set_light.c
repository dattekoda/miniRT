/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:27:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 21:53:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "world.h"
#include "libft.h"

t_hitter		*line_to_light(const char *line);
static void		clear_light_list(t_list *light_list);

int	set_light(t_world *world, const t_list *line_list)
{
	t_hitter	*new_light;

	while (line_list)
	{
		if (match_identifier(line_list->content, &g_light_info) == SUCCESS)
		{
			new_light = line_to_light(line_list->content);
			if (!new_light)
			{
				clear_light_list(&world->light_list);
				return (FAILURE);
			}
			ft_lstadd_back(&world->light_list, new_light);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}

/*
@brief ft_lstclear(&world->light_list, clear_sphere)でもいいけど、
こっちだとlightの形が異なったりノードそれぞれで形が変化してもOK
*/
static void	clear_light_list(t_list *light_list)
{
	t_list		*next;
	t_hitter	*light;

	while (light_list)
	{
		next = light_list->next;
		light = (t_hitter *)light_list->content;
		light->clear(&light);
		free(light_list);
		light_list = light_list->next;
	}
}
