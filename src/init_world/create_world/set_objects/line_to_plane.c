/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:16:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 14:16:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "parameter.h"
#include "hitter.h"
#include "vec.h"
#include "result.h"
#include <stddef.h>

int	line_to_plane(t_hitter **plane, const char *line)
{
	size_t			i;
	t_plane_param	param;
	t_color			int_color;

	i = 2;
	token_to_vec(line, &i, &param.point);
	token_to_vec(line, &i, &param.normal);
	token_to_vec(line, &i, &int_color);
	param.mat_ptr = gen_lambertian(
		gen_solid_texture(normalize_color(int_color)));
	*plane = gen_plane(param);
	if (!*plane)
		return (FAILURE);
	return (SUCCESS);
}
