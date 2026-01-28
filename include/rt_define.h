/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 10:59:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINE_H
# define RT_DEFINE_H

# include "rt_config.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define GREEN "\033[92m"
# define RESET "\033[m"

# define OPTIONS_STRING "p"

// /bin/bash -c openssl rand -hex 8
# define RANDOM_SEED_UINT64 0x629d97afad9281f2

# define DOUBLE_MANTISSA_SCALE 9.007199254740992

// how heavy to calculate to hit aabb intersection
# define COST_AABB_INTERSECTION 1

// how heavy to calculate to hit element intersection
# define COST_ELEMENT_INTERSECTION 1

# define MATERIAL_SPECIFIER "lmd"
# define TEXTURE_SPECIFIER "sbc"

#define HIT_T_MIN 1e-3

# define LIGHT_STERADIAN 0.21
#endif
