/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:53:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 20:58:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "hitter.h"
#include "parameter.h"
#include "result.h"
#include <stddef.h>

int	line_to_light(t_hitter **light, const char *line)
{
	size_t			i;
	t_sphere_param	param;
	double			ratio;
	t_color			int_color;

	i = 1;
	token_to_vec(line, &i, &param.center);
	token_to_value(line, &i, &ratio);
	param.radius = LIGHT_RADIUS;
	token_to_vec(line, &i, &int_color);
	param.mat_ptr = gen_light(scal_mul_vec(normalize_color(int_color), ratio));
	*light = gen_sphere(param);
	if (!*light)
		return (FAILURE);
	(*light)++;
	return (SUCCESS);
}
