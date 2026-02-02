/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:52:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 19:11:27 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element.h"
#include "init_world_utils.h"
#include "sphere.h"
#include "vec_utils.h"
#include "rt_define.h"

static int	line_to_sphere_param(char *line, t_sphere *sphere_param);
int			line_to_material(
				t_line_reader *line_reader,
				t_material **mat_pp,
				const t_element *element);

/*
@brief lineとgenの橋渡しなので使いやすい用にデータを加工する。
(normalize_colorを噛ませたり)
*/
int	line_to_sphere(t_hitter **sphere, char *line)
{
	t_sphere	sphere_param;

	ft_bzero(&sphere_param, sizeof(t_sphere));
	line_to_sphere_param(line, &sphere_param);
	*sphere = generate_sphere(sphere_param);
	if (!*sphere)
		return (FAILURE);
	return (SUCCESS);
}

/*
sp 0.0,0.0,20.6 12.6 10,0,255 metal solid
*/
static int	line_to_sphere_param(char *line, t_sphere *sphere_param)
{
	double			diameter;
	t_line_reader	line_reader;

	line_reader = construct_line_reader(line);
	line_reader.idx = g_info_table[SPHERE]->id_len;
	token_to_vec(&line_reader, &sphere_param->center);
	token_to_value(&line_reader, &diameter);
	sphere_param->radius = diameter * 0.5;
	if (line_to_material(
			&line_reader, &sphere_param->hitter.mat_ptr, g_info_table[SPHERE])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
