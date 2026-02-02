/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:16 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:54:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "cylinder.h"
#include "hitter.h"
#include "vec.h"

static int	line_to_cylinder_param(
				char *line, t_cylinder *cylinder_param);
int			line_to_material(
				t_line_reader *line_reader,
				t_material **mat_pp,
				const t_element *element);

int	line_to_cylinder(t_hitter **cylinder, char *line)
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
				char *line, t_cylinder *cylinder_param)
{
	t_line_reader	line_reader;
	double			diameter;

	line_reader = construct_line_reader(line);
	line_reader.idx = g_info_table[CYLINDER]->id_len;
	token_to_vec(&line_reader, &cylinder_param->center);
	token_to_vec(&line_reader, &cylinder_param->direct);
	token_to_value(&line_reader, &diameter);
	cylinder_param->radius = diameter * 0.5;
	token_to_value(&line_reader, &cylinder_param->height);
	if (line_to_material(
			&line_reader, &cylinder_param->hitter.mat_ptr, g_info_table[DISK])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
