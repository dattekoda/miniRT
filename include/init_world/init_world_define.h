/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/12 21:51:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_DEFINE_H
# define INIT_WORLD_DEFINE_H

# include <stddef.h>
# include "result.h"
#include "hitter.h"

# define PATHTRACING_AMBIENTRATIO 100.0
# define LIGHT_RADIUS 100.0

typedef t_result	(*t_skip)(const char *line, size_t *line_idx);

typedef struct s_element
{
	t_element_type	type;
	char			*id;
	size_t			id_len;
	char			*format;
	const t_skip	*skip_arr;
	int				is_infinite;
	t_hitter		*(*line_to_hitter)(const char *line);
}	t_element;

extern const t_element	g_ambient_info;
extern const t_element	g_camera_info;
extern const t_element	g_light_info;
extern const t_element	*g_info_table[];
extern const t_element	*g_infinite_table[];
extern const t_element	*g_finite_table[];

typedef enum e_element_type
{
	NOTHING,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	TRIANGLE
}	t_element_type;

enum e_option
{
	IS_PHONG = (1 << 0)
};

int	match_identifier(const char *line, const t_element *info);

#endif