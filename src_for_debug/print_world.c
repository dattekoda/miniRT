/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:17:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/20 22:12:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include <stdio.h>

void	print_vec3(t_vec3 v);
void	print_hitter_list(const t_list *list);
void	print_tree(t_hitter *node);

void	print_camera(const t_camera *camera)
{
	fprintf(stderr, "camera:\n");
	fprintf(stderr, "origin ");
	print_vec3(camera->origin);
	fprintf(stderr, "onb u      ");
	print_vec3(camera->onb.v[0]);
	fprintf(stderr, "onb v      ");
	print_vec3(camera->onb.v[1]);
	fprintf(stderr, "onb w (up) ");
	print_vec3(camera->onb.v[2]);
}

void	print_world(const t_world *world)
{
	fprintf(stderr, "world:\n");
	fprintf(stderr, "ambient color ");
	print_vec3(world->ambient_light);
	print_camera(&world->camera);
	fprintf(stderr, "lght list: ");
	print_hitter_list(world->light_list);
	print_tree(world->object_tree);
}
