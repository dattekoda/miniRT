/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:32:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/24 16:37:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_utils.h"
#include "libft.h"

static int	count_ambient_and_camera(const t_list *line_list);
bool		is_valid_line(const char *line, int option_flag);

bool	is_valid_line_list(const t_list *line_list, int option_flag)
{
	int	result;
	int	materaial_option_flag;

	materaial_option_flag = (option_flag & OPT_MATERIAL);
	result = count_ambient_and_camera(line_list);
	while (line_list)
	{
		if (!is_valid_line(line_list->content, option_flag))
			result = false;
		line_list = line_list->next;
	}
	return (result);
}

static int	count_ambient_and_camera(const t_list *line_list)
{
	size_t	ambient_count;
	size_t	camera_count;

	ambient_count = 0;
	camera_count = 0;
	while (line_list)
	{
		if (match_identifier(line_list->content, &g_ambient_info))
			ambient_count++;
		if (match_identifier(line_list->content, &g_camera_info))
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
