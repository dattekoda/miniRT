/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:17:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 20:48:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include <stdio.h>

void	print_vec3(t_vec3 v);
void	print_hitter_list(const t_list *list);
void	print_tree(t_hitter *node);

void	print_camera(const t_camera *camera)
{
	printf("camera:\n");
	printf("origin ");
	print_vec3(camera->origin);
	printf("onb u      ");
	print_vec3(camera->onb.v[0]);
	printf("onb v      ");
	print_vec3(camera->onb.v[1]);
	printf("onb w (up) ");
	print_vec3(camera->onb.v[2]);
}

void	print_world(const t_world *world)
{
	printf("world:\n");
	printf("ambient color ");
	print_vec3(world->ambient_light);
	print_camera(&world->camera);
	printf("lght list: ");
	print_hitter_list(world->light_list);
	print_tree(world->object_tree);
}
