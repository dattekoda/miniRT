/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 16:23:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "vec_utils.h"
#include "sphere.h"
#include "material.h"
#include "texture.h"
#include "rt_config.h"
#include "light.h"

static int	light_line_to_shape_param(const char *line,
	t_sphere *light_param, int option_flag);
int	line_to_material
	(const char *line, size_t *line_idx, t_material **mat_pp, const t_element *element);
static int	line_to_light_material(const char *line, size_t *line_idx,
	t_material **mat_pp, int option_flag);
static int	pam_to_light_material(t_color color, t_material **mat_pp);

/*
@brief line "L 0,4,4, 0.3, 255,255,0 4"
*/
int	line_to_light(t_hitter **light, const char *line, int option_flag)
{
	t_sphere		shape_param;

	ft_bzero(&shape_param, sizeof(t_sphere));
	if (light_line_to_shape_param(line, &shape_param, option_flag) == FAILURE)
		return (FAILURE);
	*light = generate_sphere(shape_param);
	if (!*light)
		return (FAILURE);
	return (SUCCESS);
}

/*
L 0,0,0 0.3 255,255,0 4
*/
static int	light_line_to_shape_param(const char *line, t_sphere *light_param, int option_flag)
{
	size_t	i;

	i = g_info_table[LIGHT]->id_len;
	token_to_vec(line, &i, &light_param->center);
	if (line_to_light_material(line, &i, &light_param->hitter.mat_ptr, option_flag) == FAILURE)
		return (FAILURE);
	token_to_value(line, &i, &light_param->radius);
	return (SUCCESS);
}

static int	line_to_light_material(const char *line, size_t *line_idx,
	t_material **mat_pp, int option_flag)
{
	double		ratio;
	t_color		color;

	token_to_value(line, line_idx, &ratio);
	token_to_vec(line, line_idx, &color);
	color = scal_mul_vec3(normalize_color(color), ratio);
	if (!(option_flag & OPT_ARTIFICIAL))
		color = scal_mul_vec3(color, PATHTRACING_LIGHT_STRENGTH);
	if (pam_to_light_material(color, mat_pp) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	pam_to_light_material(t_color color, t_material **mat_pp)
{
	t_texture	*texture_ptr;
	t_material	*mat_ptr;

	texture_ptr = generate_solid_texture(color);
	if (!texture_ptr)
		return (FAILURE);
	mat_ptr = generate_light(texture_ptr);
	if (!mat_ptr)
		return (FAILURE);
	*mat_pp = mat_ptr;
	return (SUCCESS);
}
