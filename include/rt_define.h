/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/16 16:01:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINE_H
# define RT_DEFINE_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define GREEN "\033[92m"
# define RESET "\033[m"

# define OPTIONS_STRING "p"

# define RANDOM_SEED_UINT64 0x629d97afad9281f2 // /bin/bash -c openssl rand -hex 8
#define DOUBLE_MANTISSA_BITS 53
#define DOUBLE_MANTISSA_SCALE (1ULL << DOUBLE_MANTISSA_BITS)

#endif
