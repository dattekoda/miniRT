/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:38:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONEBONUS_H
# define CONEBONUS_H

# include "hitter_bonus.h"
# include "material_bonus.h"

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
