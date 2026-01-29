/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_disk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:50:11 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/30 01:49:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element.h"
#include "init_world_utils.h"
#include "disk.h"
#include <stddef.h>

static void	line_to_disk_param(const char *line, t_disk *disk_param);

/*
"di 1.0,1.0,1.0 0.0,1.0,0.0 0.5 255,0,0 metal solid"
*/
int	line_to_disk(t_hitter **disk, const char *line)
{
	t_disk	disk_param;

	ft_bzero(&disk, sizeof(t_disk));
	line_to_disk_param(line, &disk_param);
	*disk = generate_disk(disk_param);
	if (!*disk)
		return (FAILURE);
	return (SUCCESS);
}

static void	line_to_disk_param(const char *line, t_disk *disk_param)
{
	size_t	i;
	double	diameter;

	i = g_info_table[DISK]->id_len;
	token_to_vec(line, &i, &disk_param->center);
	token_to_vec(line, &i, &disk_param->normal);
	token_to_value(line, &i, &diameter);
	disk_param->radius = diameter * 0.5;
	if (line_to_material(
			line, &i, &disk_param->hitter.mat_ptr, g_info_table[DISK])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
