/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:36:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/24 18:24:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "world.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "rt_config.h"
#include "rt_define.h"
#include <stdbool.h>

static t_color	get_ambient_data(const char *line, bool is_phong);
static t_color	construct_ambient(t_color raw_color, double ratio);

void	set_ambient(t_world *world, const t_list *line_list)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, &g_ambient_info))
			break ;
		line_list = line_list->next;
	}
	world->ambient = 
		get_ambient_data(line_list->content, is_phong(world->option_flag));
	return ;
}

static t_color	get_ambient_data(const char *line, bool is_phong)
{
	t_color	raw_color;
	double	ratio;
	size_t	i;

	i = 1;
	token_to_vec(line, &i, &raw_color);
	token_to_value(line, &i, &ratio);
	if (!is_phong)
		ratio *= PATHTRACING_AMBIENTSCALE;
	return (construct_ambient(raw_color, ratio));
}

static t_color	construct_ambient(t_color raw_color, double ratio)
{
	return (normalize_color(scal_mul_vec3(raw_color, ratio)));
}
