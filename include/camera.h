/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:34:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 17:07:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec.h"

typedef struct s_camera
{
	t_point3	origin;
	t_onb		onb;
	double		screen_width;
	double		screen_height;
	t_point3	high_left;
}	t_camera;

#endif
