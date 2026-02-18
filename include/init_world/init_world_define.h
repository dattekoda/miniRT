/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/11 18:47:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_DEFINE_H
# define INIT_WORLD_DEFINE_H

# include "texture.h"
# include "material.h"
# include "vec.h"
# include <stddef.h>

// TODO: UNIT_EDGE should be at rt_config.h
# define UNIT_EDGE 10

typedef t_texture	*(*t_generate_texture)(t_color color);
typedef t_material	*(*t_generate_material)(t_texture *texture_ptr);

#endif