/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 20:13:43 by ikawamuk         ###   ########.fr       */
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
	*hitter = gen_cylinder(param);
	if (!*hitter)
		return (FAILURE);
	return (SUCCESS);
}
