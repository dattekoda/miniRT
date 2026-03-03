/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:52:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/03 17:50:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element.h"
#include "init_world_utils.h"
#include "cone.h"
#include "vec_utils.h"
#include "rt_define.h"

static int		line_to_cone_param(const char *line, t_cone *cone_param);
static double	to_radians(const double degrees);

/*
@brief lineとgenの橋渡しなので使いやすい用にデータを加工する。
(normalize_colorを噛ませたり)
*/
int	line_to_cone(t_hitter **cone, const char *line)
{
	t_cone	cone_param;

	ft_bzero(&cone_param, sizeof(t_cone));
	line_to_cone_param(line, &cone_param);
	*cone = generate_cone(cone_param);
	if (!*cone)
		return (FAILURE);
	return (SUCCESS);
}

/*
"co 1.0,1.0,1.0 0,-1,0 60 0,0,255"
*/
static int	line_to_cone_param(const char *line, t_cone *cone_param)
{
	size_t			i;

	i = g_element_table[CONE]->id_len;
	token_to_vec(line, &i, &cone_param->apex);
	token_to_vec(line, &i, &cone_param->direct);
	token_to_value(line, &i, &cone_param->half_angle);
	cone_param->half_angle = to_radians(cone_param->half_angle);
	if (line_to_material(
			line, &i, &cone_param->hitter.mat_ptr, g_element_table[CONE])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*
@brief 度数法を弧度法に変換
*/
static double	to_radians(const double degrees)
{
	return (degrees * M_PI / 180.0);
}
