/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_disk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:50:11 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/02 18:55:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_to_element.h"
#include "init_world_utils.h"
#include "disk.h"
#include <stddef.h>

static int	line_to_disk_param(char *line, t_disk *disk_param);
int			line_to_material(
				t_line_reader *line_reader,
				t_material **mat_pp,
				const t_element *element);

/*
"di 1.0,1.0,1.0 0.0,1.0,0.0 0.5 255,0,0 metal solid"
*/
int	line_to_disk(t_hitter **disk, char *line)
{
	t_disk	disk_param;

	ft_bzero(&disk_param, sizeof(t_disk));
	line_to_disk_param(line, &disk_param);
	*disk = generate_disk(disk_param);
	if (!*disk)
		return (FAILURE);
	return (SUCCESS);
}

static int	line_to_disk_param(char *line, t_disk *disk_param)
{
	t_line_reader	line_reader;
	double			diameter;

	line_reader = construct_line_reader(line);
	line_reader.idx = g_info_table[DISK]->id_len;
	token_to_vec(&line_reader, &disk_param->center);
	token_to_vec(&line_reader, &disk_param->normal);
	token_to_value(&line_reader, &diameter);
	disk_param->radius = diameter * 0.5;
	if (line_to_material(
			&line_reader, &disk_param->hitter.mat_ptr, g_info_table[DISK])
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
