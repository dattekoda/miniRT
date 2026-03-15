/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 15:08:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINE_H
# define RT_DEFINE_H

# include "rt_config.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef FLT_EPSILON
#  define FLT_EPSILON	1.19209290e-7F
# endif

extern const unsigned int	g_window_width;
extern const unsigned int	g_window_height;

# define GREEN "\033[92m"
# define RESET "\033[m"

// /bin/bash -c openssl rand -hex 8
# define RANDOM_SEED_UINT64 0x629d97afad9281f2

// 2 ** (-53)
# define DOUBLE_INV_SCALE 0x3ca0000000000000

// how heavy to calculate to hit aabb intersection
# define COST_AABB_INTERSECTION 1.0

// how heavy to calculate to hit element intersection
# define COST_ELEMENT_INTERSECTION 2.8

# define HIT_T_MIN 1e-3

# define PLANE_AABB_THICKNESS 1e-3

// 0 < SAMPLES_PER_PIXEL
// should be at rt_config.h
# ifndef SAMPLES_PER_PIXEL
#  define SAMPLES_PER_PIXEL 30
# endif
# ifndef LENS_RADIUS
#  define LENS_RADIUS 0.0
# endif
# ifndef MAX_DEPTH
#  define MAX_DEPTH	3
# endif

#endif
