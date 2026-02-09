/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:36:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/09 16:36:38 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "world.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "rt_config.h"
#include "rt_define.h"
#include <stdbool.h>

static t_color	line_to_ambient_light(const char *line, bool is_phong);
static t_color	construct_ambient_light(t_color raw_color, double ratio);

void	set_ambient_light(t_world *world, const t_list *line_list, bool is_phong)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, g_info_table[AMBIENT]))
			break ;
		line_list = line_list->next;
	}
	world->ambient_light
		= line_to_ambient_light(line_list->content, is_phong);
	return ;
}

static t_color	line_to_ambient_light(const char *line, bool is_phong)
{
	t_color	raw_color;
	double	ratio;
	size_t	i;

	i = 1;
	token_to_value(line, &i, &ratio);
	token_to_vec(line, &i, &raw_color);
	if (!is_phong)
		ratio *= PATHTRACING_AMBIENTSCALE;
	return (construct_ambient_light(raw_color, ratio));
}

static t_color	construct_ambient_light(t_color raw_color, double ratio)
{
	return (scal_mul_vec3(normalize_color(raw_color), ratio));
}
