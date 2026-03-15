/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_radius.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:37:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:06:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "result.h"
#include "rt_utils.h"
#include "vec_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

char		*str_space_join(char *a, char *b);
static int	calc_radius(t_point3 light_point, t_point3 camera_origin);
static int	radius_strjoin(char **light_line, int radius);
static char	*delete_new_line(char *light_line);

/*
L 0,5,5 0.1 255,255,255 → L 0,5,5 0.1 255,255,255 30
*/
int	add_light_radius(char **light_line, t_point3 camera_origin)
{
	size_t		idx;
	t_point3	light_point;
	int			radius;

	idx = g_element_table[LIGHT]->id_len;
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
	sin_theta = sqrt(1 - cos_theta * cos_theta);
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
	*light_line = delete_new_line(*light_line);
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

static char	*delete_new_line(char *light_line)
{
	const int	len = ft_strlen(light_line);

	if (light_line[len - 1] == '\n')
		light_line[len - 1] = ' ';
	return (light_line);
}
