/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:59:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/07 07:04:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CONFIG_H
# define RT_CONFIG_H

# define PROJECT_NAME "miniRT"

// window
# define WINDOW_WIDTH 600
// camera
# define ASPECT_RATIO 0.5625 /*  (9.0 / 16.0)  */

# define LENS_RADIUS 0.0

// light
// steradian of path tracing model
// minimum light radius is 1.0
# define LIGHT_STERADIAN 0.0001

# define PATHTRACING_LIGHT_STRENGTH 101.0

# define RUSSIAN_ROULETTE_START_DEPTH 10

// 0.0 - 1.0
# define METAL_FUZZINESS 0.0
// 0.0 -
# define REFRACT_IDX 1.5

// set 0.0 - 1.0
# define LIVE_PROBABILITY_MIN 0.05

# define CHECKER_SPLIT_SIZE 20

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

// 0: ripple
// 1: block
# define BUMP_TYPE 0

// phong
# define R_PHONG_AMBIENT_COEFF 0.1
# define G_PHONG_AMBIENT_COEFF 0.1
# define B_PHONG_AMBIENT_COEFF 0.1

# define R_PHONG_DIFFUSE_COEFF 0.3
# define G_PHONG_DIFFUSE_COEFF 0.3
# define B_PHONG_DIFFUSE_COEFF 0.3

# define R_PHONG_SPECULAR_COEFF 0.6
# define G_PHONG_SPECULAR_COEFF 0.6
# define B_PHONG_SPECULAR_COEFF 0.6

# define SHININESS 15

#endif
