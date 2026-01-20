/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/20 17:04:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "cylinder.h"
#include "hitter.h"
#include "vec.h"

int	line_to_cylinder(t_hitter **hitter, const char *line)
{
	size_t		i;
	t_cylinder	cylinder;
	double		diameter;
	t_color		raw_color;

	i = g_cylinder_info.id_len;
	token_to_vec(line, &i, &cylinder.center);
	token_to_vec(line, &i, &cylinder.normal);
	token_to_value(line, &i, &diameter);
	cylinder.radius = diameter * 0.5;
	token_to_value(line, &i, &cylinder.height);
	token_to_vec(line, &i, &raw_color);
	*hitter = generate_cylinder(cylinder, normalize_color(color));
	if (!*hitter)
		return (FAILURE);
	return (SUCCESS);
}
