/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line_list_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:32:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils_bonus.h"
#include "rt_utils_bonus.h"
#include "libft.h"

static bool	is_valid_ambient_camera_count(const t_list *line_list);
bool		is_valid_line(char *line, const int option_flag);
static void	ambient_count_error(size_t count);
static void	camera_count_error(size_t count);

bool	is_valid_line_list(const t_list *line_list, const int option_flag)
{
	bool	is_valid;

	is_valid = is_valid_ambient_camera_count(line_list);
	while (line_list)
	{
		if (!is_valid_line(line_list->content, option_flag))
			is_valid = false;
		line_list = line_list->next;
	}
	return (is_valid);
}

static bool	is_valid_ambient_camera_count(const t_list *line_list)
{
	size_t	ambient_count;
	size_t	camera_count;

	ambient_count = 0;
	camera_count = 0;
	while (line_list)
	{
		if (match_identifier(line_list->content, g_element_table[AMBIENT]))
			ambient_count++;
		if (match_identifier(line_list->content, g_element_table[CAMERA]))
			camera_count++;
		line_list = line_list->next;
	}
	if (ambient_count == 1 && camera_count == 1)
		return (true);
	if (ambient_count != 1)
		ambient_count_error(ambient_count);
	if (camera_count != 1)
		camera_count_error(camera_count);
	return (false);
}

static void	ambient_count_error(size_t count)
{
	if (count > 1)
		err_rt("Set only one ambient");
	else
		err_rt("Set one ambient");
}

static void	camera_count_error(size_t count)
{
	if (count > 1)
		err_rt("Set only one camera");
	else
		err_rt("Set one camera");
}
