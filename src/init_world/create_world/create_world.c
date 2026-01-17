/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:14:11 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/17 21:42:02 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "init_world_define.h"
#include "result.h"
#include "world.h"
#include "libft.h"

void	set_ambient(t_world *world, const t_list *line_list, int is_phong);
void	set_camera(t_camera *camera, const t_list *line_list);
int		set_light(t_list **light_list, const t_list *line_list);
int		set_objects(t_world *world, t_list *line_list);

int	create_world(t_world *world, t_list *line_list)
{
	int	is_phong;

	is_phong = world->option_flag & IS_PHONG;
	set_ambient(&world->ambient, line_list, is_phong);
	set_camera(&world->camera, line_list);

	if (set_light(&world->light_list, line_list) == FAILURE)
		return (FAILURE);
	if (set_objects(world, line_list) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
