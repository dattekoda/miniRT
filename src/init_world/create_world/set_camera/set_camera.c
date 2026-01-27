/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:13:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 21:48:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "world.h"
#include "result.h"
#include "vec_utils.h"
#include "libft.h"

t_camera	get_camera_data(const char *line);
t_camera		construct_camera(t_point3 origin, t_vec3 direct, double hfov);

void	set_camera(t_camera *camera, const t_list *line_list)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, g_info_table[CAMERA]))
			break ;
		line_list = line_list->next;
	}
	*camera = get_camera_data(line_list->content);
}

t_camera	get_camera_data(const char *line)
{
	size_t		i;
	t_point3	original;
	t_vec3		direct;
	double		hfov;

	i = 1;
	token_to_vec(line, &i, &original);
	token_to_vec(line, &i, &direct);
	token_to_value(line, &i, &hfov);
	return (construct_camera(original, normalize(direct), hfov));
}
