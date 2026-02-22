/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/22 16:58:54 by khanadat         ###   ########.fr       */
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
						const char *line,
						t_sphere *light_param);
static int			line_to_light_material(
						const char *line,
						size_t *line_idx,
						t_material **mat_pp);
static t_material	*param_to_light_material(t_color color);
static t_color		calc_color(
						t_color raw_color, double ratio);

/*
@brief line "L 0,4,4, 0.3, 255,255,0 4"
*/
int	line_to_light(t_hitter **light, const char *line)
{
	t_sphere	shape_param;

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
				const char *line,
				t_sphere *light_param)
{
	size_t			line_idx;
	char			*option;
	t_solid_texture	*light_solid;

	line_idx = g_element_table[LIGHT]->id_len;
	token_to_vec(line, &line_idx, &light_param->center);
	if (line_to_light_material(
			line, &line_idx, &light_param->hitter.mat_ptr) == FAILURE)
		return (FAILURE);
	token_to_value(line, &line_idx, &light_param->radius);
	token_to_str(line, &line_idx, &option);
	if (option && ft_strchr(option, 'n'))
	{
		light_solid
			= (t_solid_texture *)light_param->hitter.mat_ptr->texture_ptr;
		light_solid->color
			= scal_mul_vec3(light_solid->color, PATHTRACING_LIGHT_STRENGTH);
	}
	return (SUCCESS);
}

static int	line_to_light_material(
				const char *line,
				size_t *line_idx,
				t_material **mat_pp)
{
	double	ratio;
	t_color	raw_color;

	token_to_value(line, line_idx, &ratio);
	token_to_vec(line, line_idx, &raw_color);
	*mat_pp = param_to_light_material(
			calc_color(raw_color, ratio));
	if (!*mat_pp)
		return (FAILURE);
	return (SUCCESS);
}

static t_color	calc_color(t_color raw_color, double ratio)
{
	return (scal_mul_vec3(normalize_color(raw_color), ratio));
}

#include "rt_debug.h"
#include <stdlib.h>
static t_material	*param_to_light_material(t_color color)
{
	t_texture	*texture_ptr;

	texture_ptr = generate_solid_texture(color);
	if (!texture_ptr)
		return (NULL);
	return (generate_light(texture_ptr));
}
