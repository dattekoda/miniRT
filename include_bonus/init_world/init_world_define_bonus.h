/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_DEFINEBONUS_H
# define INIT_WORLD_DEFINEBONUS_H

# include "texture_bonus.h"
# include "material_bonus.h"
# include "element_bonus.h"
# include "option_bonus.h"
# include "vec_bonus.h"
# include <stddef.h>

// TODO: UNIT_EDGE should be at rt_config.h

extern const t_element				*g_element_table[];
extern const t_element				*g_infinite_table[];
extern const t_element				*g_finite_table[];

extern const t_option				*g_option_table[];

#endif