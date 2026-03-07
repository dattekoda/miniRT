/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/07 16:48:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_DEFINE_H
# define INIT_WORLD_DEFINE_H

# include "texture.h"
# include "material.h"
# include "element.h"
# include "option.h"
# include "vec.h"
# include <stddef.h>

// TODO: UNIT_EDGE should be at rt_config.h
# define UNIT_EDGE 10.0

extern const t_element				*g_element_table[];
extern const t_element				*g_infinite_table[];
extern const t_element				*g_finite_table[];

extern const t_option				*g_option_table[];

#endif