/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:45:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 17:04:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "sphere.h"
#include "solid_texture.h"
#include "lambertian.h"
#include "vec_utils.h"

static void	line_to_shape_param(const char *line,
	t_sphere *shape_param, t_color *color);

/*
@brief lineとgenの橋渡しなので使いやすい用にデータを加工する。(normalize_colorを噛ませたり)
*/
int	line_to_sphere(t_hitter **sphere, const char *line)
{
	t_sphere	shape_param;
	t_color		color;
	t_material	*mat_p;
	t_texture	*texture_p;

	line_to_shape_param(line, &shape_param, &color);
	texture_p = gen_solid_texture(color);
	if (!texture_p)
		return (FAILURE);
	mat_p = gen_lambertian(texture_p);
	if (!mat_p)
		return (FAILURE);
	*sphere = gen_sphere(&shape_param, mat_p);
	if (!*sphere)
		return (FAILURE);
	return (SUCCESS);
}

static void	line_to_shape_param(const char *line,
	t_sphere *shape_param, t_color *color)
{
	t_sphere		shape_param;
	size_t			i;
	double			diameter;
	t_color			raw_color;

	i = g_sphere_info.id_len;
	token_to_vec(line, &i, &shape_param->center);
	token_to_value(line, &i, &diameter);
	shape_param->radius = diameter * 0.5;
	token_to_vec(line, &i, &raw_color);
	*color = normalize_color(raw_color);
	return ;
}
