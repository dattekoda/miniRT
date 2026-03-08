/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_line_list_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:03:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils_bonus.h"
#include "option_bonus.h"
#include "rt_define_bonus.h"
#include "vec_utils_bonus.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

char		*str_space_join(char *a, char *b);
int			add_light_radius(char **light_line, t_point3 camera_origin);
static int	add_option_flag(char **light_line, int option_flag);

int	preprocess_line_list(
		t_list *line_list,
		t_point3 camera_origin,
		int option_flag)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, g_element_table[LIGHT]))
		{
			if (add_light_radius((char **)&line_list->content, camera_origin)
				== FAILURE)
				return (FAILURE);
			if (add_option_flag((char **)&line_list->content, option_flag)
				== FAILURE)
				return (FAILURE);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}

/*
@brief when path_tracing_mode aka natural mode,
then add "n" to the tail of the light line in order to judge
to multiply path_tracing_light_strength
*/
static int	add_option_flag(char **light_line, int option_flag)
{
	char	*new_light_line;

	if (!(option_flag & OPT_ARTIFICIAL))
		return (SUCCESS);
	new_light_line = str_space_join(*light_line, "a");
	if (!new_light_line)
		return (FAILURE);
	free(*light_line);
	*light_line = new_light_line;
	return (SUCCESS);
}
