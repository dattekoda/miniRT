/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:59:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 21:34:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CONFIG_H
# define RT_CONFIG_H

// ambient
# define PATHTRACING_AMBIENTSCALE 100.0

// window
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1280
# endif
// camera
# ifndef ASPECT_RATIO
#  define ASPECT_RATIO 1.77777777778 /*  (16.0 / 9.0)  */
# endif

# ifndef LENS_RADIUS
#  define LENS_RADIUS 0.0
# endif

// light
# define LIGHT_RADIUS 100.0

# define PATHTRACING_LIGHT_STRENGTH 100.0

// steradian of path tracing model
# ifndef LIGHT_STERADIAN
#  define LIGHT_STERADIAN 0.21
# endif

# define RUSSIAN_ROULETTE_START_DEPTH 10

// set 0.0 - 1.0
# define LIVE_PROBABILITY_MIN 0.5

// tetxure
// 0: solid
// 1: bump
// 2: checker

# define LIGHT_TEXTURE_ID		0
# define SPHERE_TEXTURE_ID		0
# define PLANE_TEXTURE_ID		0
# define CYLINDER_TEXTURE_ID	0
# define DISK_TEXTURE_ID		0
# define CONE_TEXTURE_ID		0
# define TRIANGLE_TEXTURE_ID	0

// material
// 0: lambertian
// 1: metal
// 2: dielectric

# define LIGHT_MATERIAL_ID		0
# define SPHERE_MATERIAL_ID		0
# define PLANE_MATERIAL_ID		0
# define CYLINDER_MATERIAL_ID	0
# define DISK_MATERIAL_ID		0
# define CONE_MATERIAL_ID		0
# define TRIANGLE_MATERIAL_ID	0

#endif
