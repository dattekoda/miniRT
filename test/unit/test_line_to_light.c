/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line_to_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:48:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 19:42:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "sphere.h"
#include "hitter.h"
#include "material.h"
#include "option.h"
#include "result.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include <assert.h>

bool	vec3_equal(t_vec3 a, t_vec3 b);
void	print_vec(t_vec3 v);

int			line_to_light(t_hitter **light, const char *line, int option_flag);
static int	test_target(const char *line, int option_flag);

int	test_line_to_light(void)
{
	test_target("L 30,20,40 0.7 255,255,255", OPT_ARTIFICIAL);
	test_target("L 40,10,50 0.4 144,0,0", OPT_ARTIFICIAL);

	// test_target("L 20,10,4 0.3 212 211 41 3", 0);
	return (0);
}

static int	test_target(const char *line, int option_flag)
{
	t_hitter	*hitter_ptr;
	t_sphere	*sphere_ptr;
	t_hrec		hrec;
	size_t		line_idx;
	double		light_strength;
	t_point3	point;
	t_color		color;

	if (line_to_light(&hitter_ptr, line, option_flag) == FAILURE)
		return (FAILURE);
	sphere_ptr = (t_sphere *)hitter_ptr;
	line_idx = g_info_table[SPHERE]->id_len;
	token_to_vec(line, &line_idx, &point);
	token_to_value(line, &line_idx, &light_strength);
	token_to_vec(line, &line_idx, &color);
	assert(vec3_equal(sphere_ptr->center, point));
	// if (option_flag & OPT_ARTIFICIAL)
	// 	assert(fequal(sphere_ptr->radius, ));
	// else
	// 	;
	// path_tracingのときちゃんと球の半径が変わっているか確認する必要あり
	if (option_flag & OPT_ARTIFICIAL)
		assert(vec3_equal(hitter_ptr->mat_ptr->texture_ptr->calc_texture_value
			(hitter_ptr->mat_ptr->texture_ptr, &hrec), 
			scal_mul_vec3(normalize_color(color), light_strength)));
	else
		;
	assert(hitter_ptr->has_aabb == true);
	assert(vec3_equal(hitter_ptr->aabb.centroid, scal_mul_vec3(point, 2)));
	assert(hitter_ptr->mat_ptr != NULL);
	assert(hitter_ptr->mat_ptr->texture_ptr != NULL);
	hitter_ptr->clear(hitter_ptr);
	return (SUCCESS);
}
