/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 20:14:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "vec_utils.h"
#include "parameter.h"
#include "rt_config.h"
#include "light.h"

int	line_to_light(t_hitter **light, const char *line)
{
	size_t			i;
	t_sphere_param	param;
	double			ratio;
	t_color			int_color;

	i = 1;
	token_to_vec(line, &i, &param.center);
	token_to_value(line, &i, &ratio);
	token_to_vec(line, &i, &int_color);
	param.radius = LIGHT_RADIUS;
	*light = gen_sphere(param);
	if (!*light)
		return (FAILURE);
	return (SUCCESS);
}
