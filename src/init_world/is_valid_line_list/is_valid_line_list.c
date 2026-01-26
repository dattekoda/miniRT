/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:32:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 21:37:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_utils.h"
#include "libft.h"

static bool	is_valid_ambient_camera_count(const t_list *line_list);
bool		is_valid_line(char *line, const int option_flag);

bool	is_valid_line_list(const t_list *line_list, const int option_flag)
{
	int	result;

	result = is_valid_ambient_camera_count(line_list);
	while (line_list)
	{
		if (!is_valid_line(line_list->content, option_flag))
			result = false;
		line_list = line_list->next;
	}
	return (result);
}

static bool	is_valid_ambient_camera_count(const t_list *line_list)
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
		return (true);
	if (ambient_count != 1)
		err_rt("Set only one ambient");
	if (camera_count != 1)
		err_rt("Set only one camera");
	return (false);
}
