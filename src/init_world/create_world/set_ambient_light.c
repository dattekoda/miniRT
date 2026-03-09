/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:36:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/07 22:23:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "world.h"
#include "vec_utils.h"
#include "rt_utils.h"
#include "rt_config.h"
#include "rt_define.h"
#include <stdbool.h>

t_color			line_to_ambient_light(const char *line);
static t_color	construct_ambient_light(t_color raw_color, double ratio);

void	set_ambient_light(t_color *ambient_light, const t_list *line_list)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, g_element_table[AMBIENT]))
			break ;
		line_list = line_list->next;
	}
	*ambient_light
		= line_to_ambient_light(line_list->content);
	return ;
}

t_color	line_to_ambient_light(const char *line)
{
	t_color	raw_color;
	double	ratio;
	size_t	i;

	i = 1;
	token_to_value(line, &i, &ratio);
	token_to_vec(line, &i, &raw_color);
	return (construct_ambient_light(raw_color, ratio));
}

static t_color	construct_ambient_light(t_color raw_color, double ratio)
{
	return (scal_mul_vec3(normalize_color(raw_color), ratio));
}
