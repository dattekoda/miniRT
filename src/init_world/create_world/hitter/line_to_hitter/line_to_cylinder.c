/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 21:01:31 by ikawamuk         ###   ########.fr       */
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
	token_to_vec(line, &i, &cylinder.direct);
	token_to_value(line, &i, &diameter);
	cylinder.radius = diameter * 0.5;
	token_to_value(line, &i, &cylinder.height);
	token_to_vec(line, &i, &raw_color);
	*hitter = generate_cylinder(cylinder);
	if (!*hitter)
		return (FAILURE);
	return (SUCCESS);
}
