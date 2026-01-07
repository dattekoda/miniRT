/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_rt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/07 20:19:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_RT_H
# define DEFINE_RT_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef NORMALZIE_EPSILON
#  define NORMALIZE_EPSILON 1e-3
# endif

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
	size_t			str_len;
	int				(*validate)(char *line);
}	t_element_info;

extern const t_element_info	g_elem_table[];

#endif
