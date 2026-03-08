/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:34:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERABONUS_H
# define CAMERABONUS_H

# include "vec_bonus.h"

/*
@param origin ray origin of camera
@param onb v[0]:Right, v[1]:Up, v[2]:look for
@param left_top left top corner of the screen
*/
typedef struct s_camera
{
	t_point3	origin;
	t_onb		onb;
	double		width;
	double		height;
	t_point3	left_top;
}	t_camera;

#endif
