/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 19:50:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_H
# define INIT_WORLD_H

#include <stddef.h>

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

typedef struct s_element_info
{
	t_element_type	type;
	char 			*str;
	size_t			str_length;
	char			*format = "\x1b[0m""A [lighting ratio] ""\x1b[31m""R"",""\x1b[32m""G"",""\x1b[34m""B""\x1b[0m";
	int				(*validate)(char *line);
	int				(*set_object)(char *line);
}	t_element_info;

extern const t_element_info	g_elem_table[];

typedef const char** t_errmsg;

t_errmsg ambient = {
	"invalid lighting ratio in range ",
	"R,G,B[0,255] colors invalid format"
};

t_errmsg camera  = {
}

#endif