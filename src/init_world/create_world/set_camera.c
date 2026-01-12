/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:09:34 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 21:50:12 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "world.h"
#include "libft.h"

static t_camera	line_to_camera(const char *line);

void	set_camera(t_world *world, const t_list *line_list)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, &g_camera_info) == SUCCESS)
			break ;
		line_list = line_list->next;
	}
	world->camera = line_to_camera(line_list->content);
}

t_camera	line_to_camera(const char *line)
{
	size_t		i;
	t_point3	original;
	t_vec3		direct;
	double		hfov;

	i = 1;
	token_to_vec(line, &i, &original);
	token_to_vec(line, &i, &direct);
	token_to_value(line, &i, &hfov);
	return (construct_camera(original, direct, hfov));
}
