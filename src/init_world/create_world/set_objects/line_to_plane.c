/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:15:33 by ikawamuk          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/15 21:06:01 by khanadat         ###   ########.fr       */
=======
/*   Updated: 2026/01/16 13:42:26 by ikawamuk         ###   ########.fr       */
>>>>>>> 8ef67f5 (update:)
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "parameter.h"
#include "hitter.h"
#include "vec.h"
<<<<<<< HEAD
#include <parameter.h>
=======
#include "result.h"
#include <stddef.h>
>>>>>>> 8ef67f5 (update:)

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
