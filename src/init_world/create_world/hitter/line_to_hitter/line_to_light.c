/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/20 20:08:05 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "vec_utils.h"
#include "sphere.h"
#include "rt_config.h"
#include "light.h"

static void	line_to_shape_param(const char *line,
	t_sphere *shape_param, t_color *color);

/*
@brief line "L 0,4,4, 0.3, 255,255,0 4"
*/
int	line_to_light(t_hitter **light, const char *line, bool is_phong)
{
	t_sphere		shape_param;
	t_color			color;
	t_texture		*texture_ptr;
	t_material		*mat_ptr;

	ft_bzero(&shape_param, sizeof(t_sphere));
	line_to_shape_param(line, &shape_param, &color);
	if (is_phong)
		color = scal_mul_vec3(color, PATHTRACING_LIGHT_STRENGTH);
	texture_ptr = generate_solid_texture(color);
	if (!texture_ptr)
		return (FAILURE);
	mat_ptr = generate_light(texture_ptr);
	if (!mat_ptr)
		return (FAILURE);
	*light = generate_sphere(shape_param, mat_ptr);
	if (!*light)
		return (FAILURE);
	return (SUCCESS);
}

/*
L 0,0,0 0.3 255,255,0 4
*/
static void	line_to_shape_param(const char *line,
	t_sphere *shape_param, t_color *color)
{
	t_sphere		shape_param;
	t_color			raw_color;
	size_t			i;
	double			ratio;

	i = g_light_info.id_len;
	token_to_vec(line, &i, &shape_param->center);
	token_to_value(line, &i, &ratio);
	token_to_vec(line, &i, &raw_color);
	*color = scal_mul_vec3(normalize_color(raw_color), ratio);
	token_to_vec(line, &i, &shape_param->radius);
	return ;
}
