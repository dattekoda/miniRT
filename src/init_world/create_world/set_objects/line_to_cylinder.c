/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:20:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/14 04:43:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "hitter.h"
#include "vec.h"

t_hitter	*line_to_cylinder(const char *line)
{
	size_t				i;
	t_cylinder_param	param;
	double				diameter;
	t_color				int_color;

	i = 2;
	token_to_vec(line, &i, &param.center);
	token_to_vec(line, &i, &param.normal);
	token_to_value(line, &i, &diameter);
	param.radius = diameter * 0.5;
	token_to_value(line, &i, &param.height);
	token_to_vec(line, &i, &int_color);
	param.mat_ptr = gen_lambertian(
			gen_solid_texture(normalize_color(int_color)));
	return (gen_cylinder(param));
}
