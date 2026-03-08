/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_define_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINEBONUS_H
# define RT_DEFINEBONUS_H

# include "rt_config_bonus.h"

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
