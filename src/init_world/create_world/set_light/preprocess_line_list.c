/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_line_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:29:18 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/27 20:59:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_define.h"
#include "vec_utils.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

int			add_light_radius(char **light_line, t_point3 camera_origin);
static int	calc_radius(t_point3 light_point, t_point3 camera_origin);
static int	radius_strjoin(char **light_line, int radius);
static char	*str_space_join(char *a, char *b);

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


#include <stdio.h>
/*
L 0,5,5 0.1 255,255,255 → L 0,5,5 0.1 255,255,255 30
*/
int	add_light_radius(char **light_line, t_point3 camera_origin)
{
	size_t		idx;
	t_point3	light_point;
	int			radius;

	idx = g_light_info.id_len;
	token_to_vec(*light_line, &idx, &light_point);
	radius = calc_radius(light_point, camera_origin) + 1;
	if (radius_strjoin(light_line, radius) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	calc_radius(t_point3 light_point, t_point3 camera_origin)
{
	int		radius_in_int;
	double	cos_theta;
	double	sin_theta;
	double	distance;

	cos_theta = 1 - (LIGHT_STERADIAN / (2 * M_PI));
	sin_theta = sqrt(1 - pow(cos_theta, 2));
	distance = length_vec3(sub_vec3(light_point, camera_origin));
	radius_in_int = (int)round(distance * sin_theta);
	return (radius_in_int);
}

static int	radius_strjoin(char **light_line, int radius)
{
	char	*new_light_line;
	char	*str_radius;

	str_radius = ft_itoa(radius);
	if (!str_radius)
		return (FAILURE);
	new_light_line = str_space_join(*light_line, str_radius);
	if (!new_light_line)
	{
		free(str_radius);
		return (FAILURE);
	}
	free(str_radius);
	free(*light_line);
	*light_line = new_light_line;
	return (SUCCESS);
}

static char	*str_space_join(char *a, char *b)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(a) + ft_strlen(b) + 2;
	dst = ft_calloc(size, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, a, size);
	ft_strlcat(dst, " ", size);
	ft_strlcat(dst, b, size);
	return (dst);
}
