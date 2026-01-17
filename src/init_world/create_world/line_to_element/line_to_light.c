/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 21:42:03 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "vec_utils.h"
#include "sphere.h"
#include "rt_config.h"
#include "light.h"

static void	line_to_shape_param(const char *line,
	t_sphere *shape_param, t_color *raw_color);

int	line_to_light(t_hitter **light, const char *line)
{
	t_sphere		shape_param;
	t_color			raw_color;
	t_texture		*texture_p;
	t_material		*mat_p;

	line_to_shape_param(line, &shape_param, &raw_color);
	texture_p = gen_solid_texture(normalize(raw_color));
	if (!textuere_p)
		return (NULL);
	mat_p = gen_light(texture_p);
	if (!mat_p)
		return (NULL);
	*light = gen_sphere(shape_param, mat_p);
	if (!*light)
		return (FAILURE);
	return (SUCCESS);
}

static void	line_to_shape_param(const char *line,
	t_sphere *shape_param, t_color *raw_color)
{
	t_sphere		shape_param;
	size_t			i;
	double			ratio;
	t_color			raw_color;

	i = g_light_info.id_len;
	token_to_vec(line, &i, &shape_param->center);
	token_to_value(line, &i, &ratio);
	token_to_vec(line, &i, raw_color);
	shape_param->radius = LIGHT_RADIUS;
	return ;
}
