/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:59:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 15:49:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CONFIG_H
# define RT_CONFIG_H

// ambient
# define PATHTRACING_AMBIENTSCALE 100.0

// camera
# ifndef ASPECT_RATIO
#  define ASPECT_RATIO 1.77777777778 /*  (16.0 / 9.0)  */
# endif

# ifndef LENS_RADIUS
#  define LENS_RADIUS 0.0
# endif

// light
# define LIGHT_RADIUS 100.0

// tetxure
# define SPHERE_TEXTURE_ID 0

// material
# define SPHERE_MATERIAL_ID 0

#endif
