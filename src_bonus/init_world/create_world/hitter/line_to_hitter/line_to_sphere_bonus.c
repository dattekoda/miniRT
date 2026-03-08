/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_sphere_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:52:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:31:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element_bonus.h"
#include "init_world_utils_bonus.h"
#include "sphere_bonus.h"
#include "vec_utils_bonus.h"
#include "rt_define_bonus.h"

static int	line_to_sphere_param(const char *line, t_sphere *sphere_param);

/*
@brief lineとgenの橋渡しなので使いやすい用にデータを加工する。
(normalize_colorを噛ませたり)
*/
int	line_to_sphere(t_hitter **sphere, const char *line)
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
static int	line_to_sphere_param(const char *line, t_sphere *sphere_param)
{
	double			diameter;
	size_t			i;

	i = g_element_table[SPHERE]->id_len;
	token_to_vec(line, &i, &sphere_param->center);
	token_to_value(line, &i, &diameter);
	sphere_param->radius = diameter * 0.5;
	if (line_to_material(
			line, &i, &sphere_param->hitter.mat_ptr, g_element_table[SPHERE])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
