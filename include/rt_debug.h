#ifndef RT_DEBUG_H
#define RT_DEBUG_H
#include "hitter.h"
#include "libft.h"
#include "hitter_arr.h"

void	print_hitter(t_hitter *hitter);
void	print_hitter_list(const t_list *list);
void	print_hitter_arr(t_hitter_arr arr);

void	print_line_list(const t_list *line_list);

void	print_material(const t_material *material);

void	print_pixel_arr(t_color *pixel_arr);
void	print_raw_rgb_arr(int *raw_rgb_arr);

void	print_ray(const t_ray *ray);

void	print_vec3(t_vec3 v);
void	print_vec2(t_vec2 v);

#endif