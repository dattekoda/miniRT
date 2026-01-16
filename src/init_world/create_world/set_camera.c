/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:09:34 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 16:44:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "world.h"
#include "libft.h"

t_camera	get_camera_data(const char *line);

void	set_camera(t_world *world, const t_list *line_list)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, &g_camera_info) == SUCCESS)
			break ;
		line_list = line_list->next;
	}
	world->camera = get_camera_data(line_list->content);
}

static t_camera	get_camera_data(const char *line)
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

static t_camera	construct_camera(t_point3 origin, t_vec3 direct, double hfov)
{
	t_camera	camera;

	camera.origin = origin;
	camera.screen_size = 
}
