/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/19 20:09:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINE_H
# define RT_DEFINE_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef LIGHT_STERADIAN
#  define LIGHT_STERADIAN 0.21
# endif

# define GREEN "\033[92m"
# define RESET "\033[m"

# define OPTIONS_STRING "p"

// /bin/bash -c openssl rand -hex 8
# define RANDOM_SEED_UINT64 0x629d97afad9281f2

# define DOUBLE_MANTISSA_SCALE 9.007199254740992

#endif
