/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:14:11 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/11 18:41:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "option.h"
#include "result.h"
#include "world.h"
#include "libft.h"

void	set_ambient_light(
			t_world *world,
			const t_list *line_list,
			bool is_phong);
void	set_camera(t_camera *camera, const t_list *line_list);
int		set_light(t_world *world, const t_list *line_list, int option_flag);
int		set_objects(t_world *world, t_list *line_list, int option_flag);


#include <stdio.h>
int	create_world(t_world *world, t_list *line_list, int option_flag)
{
	printf("HERE1\n");
	set_ambient_light(world, line_list, option_flag & OPT_ARTIFICIAL);
	printf("HERE2\n");
	set_camera(&world->camera, line_list);
	printf("HERE3\n");
	if (set_light(world, line_list, option_flag) == FAILURE)
		return (FAILURE);
	printf("HERE4\n");
	if (set_objects(world, line_list, option_flag) == FAILURE)
		return (FAILURE);
	printf("HERE5\n");
	return (SUCCESS);
}
