/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_disk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:50:11 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/21 15:08:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "init_world_utils.h"
#include "disk.h"
#include <stddef.h>

int	line_to_disk(t_hitter **disk, const char *line)
{
	size_t			i;
	double			diameter;
	t_disk			param;
	t_color			raw_color;

	i = g_disk_info.id_len;
	token_to_vec(line, &i, &param.center);
	token_to_vec(line, &i, &param.normal);
	token_to_vec(line, &i, &diameter);
	param.radius = diameter * 0.5;
	token_to_vec(line, &i, &raw_color);
	*disk = generate_disk(param, ray_color);
	if (!*disk)
		return (FAILURE);
	return (SUCCESS);
}

static void	line_to_disk_param(const char *line, 
	t_disk *disk_param, t_color *raw_color)
{
	size_t	i;
	double	diameter;

	i = g_disk_info.id_len;
	token_to_vec(line, &i, &disk_param->center);
	token_to_vec(line, &i, &disk_param->normal);
	token_to_vec(line, &i, &diameter);
	param.radius = diameter * 0.5;
	token_to_vec(line, &i, &raw_color);
	return ;
}
