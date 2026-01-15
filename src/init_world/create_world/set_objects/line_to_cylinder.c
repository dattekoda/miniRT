/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:20:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 21:06:42 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "hitter.h"
#include "vec.h"
#include "parameter.h"

int	line_to_cylinder(t_hitter **hitter, const char *line)
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
	*(hitter) = gen_cylinder(param);
	*(hitter + 1) = gen_disk(param);
	*(hitter + 2) = gen_disk(param);
	if (!*hitter || !*(hitter + 1) || !*(hitter + 2))
		return (FAILURE);
	return (SUCCESS);
}
