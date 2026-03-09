/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:13:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils_bonus.h"
#include "world_bonus.h"
#include "result_bonus.h"
#include "vec_utils_bonus.h"
#include "libft.h"

t_camera	get_camera_data(const char *line);
t_camera	construct_camera(t_point3 origin, t_vec3 direct, double hfov);

void	set_camera(t_camera *camera, const t_list *line_list)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, g_element_table[CAMERA]))
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

	i = (size_t)g_element_table[CAMERA]->id_len;
	token_to_vec(line, &i, &original);
	token_to_vec(line, &i, &direct);
	token_to_value(line, &i, &hfov);
	return (construct_camera(original, normalize(direct), hfov));
}
