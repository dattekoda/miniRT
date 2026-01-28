/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:45:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 16:05:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_info.h"
#include "init_world_utils.h"
#include "sphere.h"
#include "vec_utils.h"
#include "rt_define.h"

static int	line_to_sphere_param(const char *line, 
	t_sphere *sphere_param);
int	line_to_material
	(const char *line, size_t *line_idx, 
		t_material **mat_pp, const t_element *element);

/*
@brief lineとgenの橋渡しなので使いやすい用にデータを加工する。(normalize_colorを噛ませたり)
*/
int	line_to_sphere(t_hitter **sphere, const char *line/* , bool is_option_m */)
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
static int	line_to_sphere_param(const char *line,
	t_sphere *sphere_param)
{
	double			diameter;
	size_t			i;

	i = g_info_table[SPHERE]->id_len;
	token_to_vec(line, &i, &sphere_param->center);
	token_to_value(line, &i, &diameter);
	sphere_param->radius = diameter * 0.5;
	if (line_to_material
		(line, &i, &sphere_param->hitter.mat_ptr, *g_info_table[SPHERE]) 
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
