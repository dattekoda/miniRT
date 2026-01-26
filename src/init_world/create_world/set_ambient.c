/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:36:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 21:51:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "world.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "rt_config.h"
#include "rt_define.h"
#include <stdbool.h>

t_color			get_ambient_data(const char *line, bool is_phong);
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
		get_ambient_data(line_list->content, world->option_flag & OPT_ARTIFICIAL);
	return ;
}

t_color	get_ambient_data(const char *line, bool is_phong)
{
	t_color	raw_color;
	double	ratio;
	size_t	i;

	i = 1;
	token_to_value(line, &i, &ratio);
	token_to_vec(line, &i, &raw_color);
	if (!is_phong)
		ratio *= PATHTRACING_AMBIENTSCALE;
	return (construct_ambient(raw_color, ratio));
}

static t_color	construct_ambient(t_color raw_color, double ratio)
{
	return (scal_mul_vec3(normalize_color(raw_color), ratio));
}
