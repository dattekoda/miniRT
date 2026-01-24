/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:52:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/24 20:40:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "init_world_utils.h"
#include "validate_utils.h"
#include "vec_utils.h"
#include "world.h"
#include "rt_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

static int	radius_strjoin(char **light_line, int radius);
static int	add_light_radius(char **light_line, t_point3 camera_origin);
static int	new_light_node(t_list **new_list, const char *line, bool is_phong);
static int	preprocess_line_list(t_list *line_list, t_point3 camera_origin);
int			line_to_light(t_hitter **light, const char *line, bool is_phong);

int	set_light(t_world *world, t_list *line_list)
{
	t_list	*new_node;
	bool	phong_flag;

	phong_flag = world->option_flag & OPT_ARTIFICIAL;
	if (preprocess_line_list(line_list, world->camera.origin) == FAILURE)
		return (FAILURE);
	while (line_list)
	{
		if (match_identifier(line_list->content, &g_light_info))
		{
			if (new_light_node
				(&new_node, line_list->content, phong_flag) == FAILURE)
			{
				ft_lstclear(&world->light_list, clear_hitter);
				return (FAILURE);
			}
			ft_lstadd_back(&world->light_list, new_node);
		}
		line_list = line_list->next;
	}
	return (SUCCESS);
}

static int	new_light_node(t_list **new_list, const char *line, bool is_phong)
{
	t_hitter	*new_light;

	if (line_to_light(&new_light, line, is_phong) == FAILURE)
		return (FAILURE);
	*new_list = ft_lstnew(new_light);
	if (!*new_list)
	{
		new_light->clear(&new_light);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	preprocess_line_list(t_list *line_list, t_point3 camera_origin)
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
static int	add_light_radius(char **light_line, t_point3 camera_origin)
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
