/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/23 16:24:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_DEFINE_H
# define INIT_WORLD_DEFINE_H

# define T_AABB	1.0f
# define T_TRI	1.0f

# define PATHTRACING_LIGHT_STRENGTH 100

enum e_option
{
	ARTIFICIAL = (1 << 0),
	MATERIAL = (1 << 1),
};

typedef struct s_option
{
	char			*str;
	enum e_option	flag;
}	t_option;

typedef t_texture	*(*t_generate_texture)(t_color color);
typedef t_material	*(*t_generate_material)(t_texture *texture_ptr);

#endif