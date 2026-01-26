/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_line_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:29:18 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 20:05:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_define.h"
#include "vec_utils.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

int			add_light_radius(char **light_line, t_point3 camera_origin);
static int	radius_strjoin(char **light_line, int radius);

int	preprocess_line_list(t_list *line_list, t_point3 camera_origin)
{
	while (line_list)
	{
		if (match_identifier(line_list->content, &g_light_info))
		{
			if (add_light_radius((char **)&line_list->content, camera_origin) == FAILURE)
				return (FAILURE);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}

/*
L 0,5,5 0.1 255,255,255 → L 0,5,5 0.1 255,255,255 30
*/
int	add_light_radius(char **light_line, t_point3 camera_origin)
{
	size_t		idx;
	t_point3	light_point;
	double		distance;
	int			radius;

	idx = g_light_info.id_len;
	token_to_vec(*light_line, &idx, &light_point);
	distance = length_vec3(sub_vec3(light_point, camera_origin));
	radius = (int)(distance 
		* sqrt(LIGHT_STERADIAN / M_PI - pow(LIGHT_STERADIAN / (2 * M_PI), 2)));
	if (radius_strjoin(light_line, radius) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	radius_strjoin(char **light_line, int radius)
{
	char	*new_light_line;
	char	*str_radius;
	size_t	new_light_line_len;

	str_radius = ft_itoa(radius);
	if (!str_radius)
		return (FAILURE);
	new_light_line_len = ft_strlen(*light_line) 
		+ ft_strlen(str_radius) + 2;
	new_light_line = ft_calloc(new_light_line_len, sizeof(char));
	if (!new_light_line)
	{
		free(str_radius);
		return (FAILURE);
	}
	ft_strlcpy(new_light_line, *light_line, new_light_line_len);
	ft_strlcat(new_light_line, " ", new_light_line_len);
	ft_strlcat(new_light_line, str_radius, new_light_line_len);
	free(*light_line);
	free(str_radius);
	*light_line = new_light_line;
	return (SUCCESS);
}
