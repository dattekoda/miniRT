/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:45:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 19:14:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "sphere.h"
#include "solid_texture.h"
#include "vec_utils.h"

/*
@brief lineとgenの橋渡しなので使いやすい用にデータを加工する。(normalize_colorを噛ませたり)
*/
int	line_to_sphere(t_hitter **sphere, const char *line)
{
	size_t			i;
	t_sphere		shape_param;
	double			diameter;
	t_color			raw_color;

	i = g_sphere_info;
	token_to_vec(line, &i, &shape_param.center);
	token_to_value(line, &i, &diameter);
	shape_param.radius = diameter * 0.5;
	token_to_vec(line, &i, &raw_color);
	*sphere = gen_sphere(*sphere, noramlize_color(raw_color));
	if (!*sphere)
		return (FAILURE);
	return (SUCCESS);
}
