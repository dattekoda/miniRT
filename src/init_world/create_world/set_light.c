/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:27:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/14 17:12:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "world.h"
#include "libft.h"

t_hitter	*line_to_light(const char *line);
static void	clear_light(void *content);

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
				ft_lstclear(&world->light_list, clear_light);
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
static void	clear_light(void *content)
{
	t_hitter	*light;

	light = (t_hitter *)content;
	light->clear(&light);
}
