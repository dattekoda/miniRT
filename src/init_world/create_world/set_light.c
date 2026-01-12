/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:27:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/11 20:16:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "world.h"
#include "libft.h"

int	set_light(t_world *world, const t_list *line_list)
{
	t_hitter	*new_light;

	while (line_list)
	{
		if (!ft_strncmp(line_list->content, "L", 1))
		{
			new_light = line_to_light(line_list->content);
			if (!new_light)
				return (clear_light_list(world->light_list), FAILURE);
			ft_lstadd_back(&world->light_list, new_light);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}

static t_hitter	*line_to_light(const char *line)
{
	size_t		i;
	t_point3	point;
	double		ratio;
	t_color		int_color;

	i = 1;
	line_to_vec(line, &i, &point);
	line_to_value(line, &i, &ratio);
	line_to_vec(line, &i, &int_color);
	return (gen_light(point, ratio, int_color));
}

static t_hitter	*gen_light(t_point3 point, double ratio, t_color int_color)
{
	t_color		color;
	t_material	*mat_ptr;

	color = scal_mul_vec(normalize_color(int_color), ratio);
	mat_ptr = (t_material *)gen_light_material(color);
	if (!mat_ptr)
		return (NULL);
	return (gen_sphere(point, LIGHT_RADIUS, mat_ptr));
}
