/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:09:34 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/11 20:11:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "world.h"
#include "libft.h"

static t_camera	line_to_camera(const char *line);

void	set_camera(t_world *world, const t_list *line_list)
{
	while (line_list)
	{
		if (!ft_strncmp(line_list->content, "C", 1))
			break ;
		line_list = line_list->next;
	}
	world->camera = line_to_camera(line_list->content);
}

static t_camera	line_to_camera(const char *line)
{
	size_t		i;
	t_point3	original;
	t_vec3		direct;
	double		hfov;

	i = 1;
	line_to_vec(line, &i, &original);
	line_to_vec(line, &i, &direct);
	line_to_value(line, &i, &hfov);
	return (construct_camera(original, direct, hfov));
}
