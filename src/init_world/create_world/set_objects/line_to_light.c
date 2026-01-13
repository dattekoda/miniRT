/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:53:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/13 23:50:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "hitter.h"

t_hitter	*line_to_light(const char *line)
{
	size_t		i;
	t_point3	point;
	double		ratio;
	t_color		int_color;
	t_color		color;

	i = 1;
	token_to_vec(line, &i, &point);
	token_to_value(line, &i, &ratio);
	token_to_vec(line, &i, &int_color);
	color = scal_mul_vec(normalize_color(int_color), ratio);
	return (gen_sphere(point, LIGHT_RADIUS, gen_light_material(color)));
}
