/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:38:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/10 22:27:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "hitter.h"
# include "material.h"

typedef struct s_cone
{
	t_hitter	hitter;
	t_vec3		direct;
	double		half_angle; // radian
	t_point3	center;
}	t_cone;

t_hitter	*generate_cone(t_cone cone_param);

#endif
