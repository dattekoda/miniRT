/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:32:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 16:44:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_utils.h"
#include "libft.h"

static int	count_ambient_and_camera(const t_list *line_list);
int			validate_line(char *line);

int	validate_line_list(const t_list *line_list)
{
	int	rev;

	rev = count_ambient_and_camera(line_list);
	while (line_list)
	{
		if (validate_line(line_list->content) == FAILURE)
			rev = FAILURE;
		line_list = line_list->next;
	}
	return (rev);
}

static int	count_ambient_and_camera(const t_list *line_list)
{
	size_t	ambient_count;
	size_t	camera_count;

	ambient_count = 0;
	camera_count = 0;
	while (line_list)
	{
		if (match_identifier(line_list->content, &g_ambient_info) == SUCCESS)
			ambient_count++;
		if (match_identifier(line_list->content, &g_camera_info) == SUCCESS)
			camera_count++;
		line_list = line_list->next;
	}
	if (ambient_count == 1 && camera_count == 1)
		return (SUCCESS);
	if (ambient_count != 1)
		err_rt("set only one ambient");
	if (camera_count != 1)
		err_rt("set only one camera");
	return (FAILURE);
}
