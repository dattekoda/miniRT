/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:34:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/11 19:18:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vec.h"

typedef struct s_camera
{
	t_point3	origin;
	t_point3	ltop_corner;
	t_vec3		hori;
	t_vec3		vert;
	t_vec3		onb[3];
	double		lens_rad;
}	t_camera;

#endif
