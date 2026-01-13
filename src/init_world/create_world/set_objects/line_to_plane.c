/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:15:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/14 04:39:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "hitter.h"
#include "vec.h"

t_hitter	*line_to_plane(const char *line)
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
	return (gen_plane(param));
}
