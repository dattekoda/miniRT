/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:45:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 21:06:13 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "hitter.h"
#include "vec.h"
#include <parameter.h>

/*
@brief lineとgenの橋渡しなので使いやすい用にデータを加工する。(normalize_colorを噛ませたり)
*/
int	line_to_sphere(t_hitter **sphere, const char *line)
{
	size_t			i;
	t_sphere_param	param;
	double			diameter;
	t_color			int_color;

	i = 2;
	token_to_vec(line, &i, &param.center);
	token_to_value(line, &i, &diameter);
	param.radius = diameter * 0.5;
	token_to_vec(line, &i, &int_color);
	param.mat_ptr = gen_lambertian(
		gen_solid_texture(normalize_color(int_color)));
	*sphere = gen_sphere(param);
	if (!*sphere)
		return (FAILURE);
	return (SUCCESS);
}
