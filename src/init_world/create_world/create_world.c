/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:14:11 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/07 22:24:34 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "option.h"
#include "result.h"
#include "world.h"
#include "libft.h"

void	set_ambient_light(t_color *ambient_light, const t_list *line_list);
void	set_camera(t_camera *camera, const t_list *line_list);
int		set_light(t_world *world, const t_list *line_list, int option_flag);
int		set_objects(t_hitter **obj_tree, t_list *line_list, int option_flag);

int	create_world(t_world *world, t_list *line_list, int option_flag)
{
	set_ambient_light(&world->ambient_light, line_list);
	set_camera(&world->camera, line_list);
	if (set_light(world, line_list, option_flag) == FAILURE)
		return (FAILURE);
	if (set_objects(&world->object_tree, line_list, option_flag) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
