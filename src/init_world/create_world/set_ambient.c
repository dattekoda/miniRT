/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:36:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 14:17:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "world.h"
#include "libft.h"

static t_color	get_ambient_data(const char *line, int is_phong);

void	set_ambient(t_world *world, const t_list *line_list)
{
	int	is_phong;

	while (line_list)
	{
		if (match_identifier(line_list->content, &g_ambient_info) == SUCCESS)
			break ;
		line_list = line_list->next;
	}
	is_phong = world->option_flag & IS_PHONG;
	world->ambient = get_ambient_data(line_list->content, is_phong);
}

static t_color	get_ambient_data(const char *line, int is_phong)
{
	t_color	color;
	double	ratio;
	size_t	i;

	i = 1;
	token_to_vec(line, &i, &color);
	token_to_value(line, &i, &ratio);
	if (!is_phong)
		ratio *= PATHTRACING_AMBIENTRATIO;
	return (normalize_color(scal_mul_vec(color, ratio)));
}
