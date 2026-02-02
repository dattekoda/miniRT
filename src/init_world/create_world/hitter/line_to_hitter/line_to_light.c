/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 19:18:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "vec_utils.h"
#include "sphere.h"
#include "material.h"
#include "texture.h"
#include "rt_config.h"
#include "light.h"

static int			light_line_to_shape_param(
						char *line,
						t_sphere *light_param);
static int			line_to_light_material(
						t_line_reader *line_reader,
						t_material **mat_pp,
						int option_flag);
static t_material	*param_to_light_material(t_color color);
static t_color		calc_color(
						t_color raw_color,
						double ratio,
						int option_flag);

/*
@brief line "L 0,4,4, 0.3, 255,255,0 4"
*/
int	line_to_light(t_hitter **light, char *line)
{
	t_sphere	shape_param;

	ft_bzero(&shape_param, sizeof(t_sphere));
	if (light_line_to_shape_param(line, &shape_param) == FAILURE)
		return (FAILURE);
	*light = generate_sphere(shape_param);
	if (!*light)
		return (FAILURE);
	return (SUCCESS);
}

/*
L 0,0,0 0.3 255,255,0 4
*/
static int	light_line_to_shape_param(
				char *line,
				t_sphere *light_param)
{
	t_line_reader	line_reader;

	line_reader = construct_line_reader(line);
	line_reader.idx = g_info_table[LIGHT]->id_len;
	token_to_vec(&line_reader, &light_param->center);
	if (line_to_light_material(
			&line_reader, &light_param->hitter.mat_ptr) == FAILURE)
		return (FAILURE);
	token_to_value(&line_reader, &light_param->radius);
	return (SUCCESS);
}

static int	line_to_light_material(
				t_line_reader *line_reader,
				t_material **mat_pp,
				int option_flag)
{
	double	ratio;
	t_color	raw_color;

	token_to_value(line_reader, &ratio);
	token_to_vec(line_reader, &raw_color);
	*mat_pp = param_to_light_material(
			calc_color(raw_color, ratio, option_flag));
	if (!*mat_pp)
		return (FAILURE);
	return (SUCCESS);
}

static t_color	calc_color(t_color raw_color, double ratio, int option_flag)
{
	t_color	color;

	if (!(option_flag & OPT_ARTIFICIAL))
		ratio *= PATHTRACING_LIGHT_STRENGTH;
	color = scal_mul_vec3(normalize_color(raw_color), ratio);
	return (color);
}

static t_material	*param_to_light_material(t_color color)
{
	t_texture	*texture_ptr;

	texture_ptr = generate_solid_texture(color);
	if (!texture_ptr)
		return (NULL);
	return (generate_light(texture_ptr));
}
