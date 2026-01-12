/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:36:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/11 20:12:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "world.h"
#include "libft.h"

static t_color	line_to_ambient(const char *line, int is_phong);

void	set_ambient(t_world *world, const t_list *line_list)
{
	while (line_list)
	{
		if (!ft_strncmp(line_list->content, "A", 1))
			break ;
		line_list = line_list->next;
	}
	world->ambient = line_to_ambient(line_list->content, (world->option_flag & IS_PHONG));
}

static t_color	line_to_cambient(const char *line, int is_phong)
{
	t_color	color;
	double	ratio;
	size_t	i;

	i = 1;
	line_to_vec(line, &i, &color);
	line_to_value(line, &i, &ratio);
	if (!is_phong)
		ratio *= PATHTRACING_AMBIENTRATIO;
	return (normalize_color(scal_mul_vec(color, ratio)));
}
