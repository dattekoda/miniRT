/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:38:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 11:47:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "hitter.h"
# include "material.h"

/*
@param half_angel radian
@param apex the highest point
*/
typedef struct s_cone
{
	t_hitter	hitter;
	t_vec3		direct;
	t_point3	apex;
	double		half_angle;
	double		cos_half_angle_sq;
}	t_cone;

t_hitter	*generate_cone(t_cone cone_param);

#endif
