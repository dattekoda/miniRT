/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/07 13:40:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "vec_utils.h"
#include "cylinder.h"
#include "hitter.h"
#include "vec.h"

static int	line_to_cylinder_param(
				const char *line, t_cylinder *cylinder_param);

int	line_to_cylinder(t_hitter **cylinder, const char *line)
{
	t_cylinder	cylinder_param;

	ft_bzero(&cylinder_param, sizeof(t_cylinder));
	if (line_to_cylinder_param(line, &cylinder_param) == FAILURE)
		return (FAILURE);
	*cylinder = generate_cylinder(cylinder_param);
	if (!*cylinder)
		return (FAILURE);
	return (SUCCESS);
}

/*
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255 lambertian checker
*/
static int	line_to_cylinder_param(
				const char *line, t_cylinder *cylinder_param)
{
	size_t		i;
	double		diameter;
	t_point3	center;

	i = g_element_table[CYLINDER]->id_len;
	token_to_vec(line, &i, &center);
	token_to_vec(line, &i, &cylinder_param->direct);
	token_to_value(line, &i, &diameter);
	cylinder_param->radius = diameter * 0.5;
	token_to_value(line, &i, &cylinder_param->height);
	cylinder_param->bottom_center
		= sub_vec3(center,
			scal_mul_vec3(cylinder_param->direct,
				cylinder_param->height * 0.5));
	if (line_to_material(
			line, &i, &cylinder_param->hitter.mat_ptr, g_element_table[DISK])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
