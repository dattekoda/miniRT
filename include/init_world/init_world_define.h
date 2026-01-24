/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 16:28:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_DEFINE_H
# define INIT_WORLD_DEFINE_H

# define T_AABB	1.0f
# define T_TRI	1.0f

# define PATHTRACING_LIGHT_STRENGTH 100

# include "texture.h"

enum e_option
{
	OPT_ARTIFICIAL = (1 << 0),
	OPT_MATERIAL = (1 << 1),
};

typedef struct s_option
{
	char			*str;
	enum e_option	flag;
}	t_option;

typedef t_texture	*(*t_generate_texture)(t_color color);
typedef t_material	*(*t_generate_material)(t_texture *texture_ptr);

#endif