/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 12:14:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINE_H
# define RT_DEFINE_H

# include "rt_config.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

extern const unsigned int	g_window_width;
extern const unsigned int	g_window_height;

# define GREEN "\033[92m"
# define RESET "\033[m"

// /bin/bash -c openssl rand -hex 8
# define RANDOM_SEED_UINT64 0x629d97afad9281f2

# define DOUBLE_INV_SCALE 0x1p-53

// how heavy to calculate to hit aabb intersection
# define COST_AABB_INTERSECTION 0.1

// how heavy to calculate to hit element intersection
# define COST_ELEMENT_INTERSECTION 0.5

# define HIT_T_MIN 1e-3

// 0 < SAMPLES_PER_PIXEL
// should be at rt_config.h
# define SAMPLES_PER_PIXEL 30
# define LENS_RADIUS 0.0
# define MAX_DEPTH	10

#endif
