#ifndef RT_DEBUG_H
#define RT_DEBUG_H

#include <stdio.h>
#include <stdlib.h> // debug
#include "world.h"
#include "hitter.h"
#include "libft.h"
#include "hitter_arr.h"
#include "split.h"

void	init_time(void);
void	print_time(void);

void	print_world(const t_world *world);

void	print_aabb(t_aabb aabb);

void	print_axis(t_axis axis);

void	print_hitter_arr(const t_hitter_arr *hit_arr);

void	print_split(const t_split *split);

void	print_hitter(t_hitter *hitter);
void	print_hitter_list(const t_list *list);
void	print_tree(t_hitter *node);

void	print_line_list(const t_list *line_list);

void	print_material(const t_material *material);

void	print_pixel_arr(t_color *pixel_arr);
void	print_raw_rgb_arr(int *raw_rgb_arr);

void	print_ray(const t_ray *ray);

void	print_vec3(t_vec3 v);
void	print_vec2(t_vec2 v);

#endif