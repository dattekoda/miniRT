/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:31:35 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/07 06:52:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "material.h"
# include "vec.h"

/*
@param center center of bottom disk
*/
typedef struct s_cylinder
{
	t_hitter	hitter;
	t_point3	center;
	t_vec3		direct;
	double		radius;
	double		height;
}	t_cylinder;

t_hitter	*generate_cylinder(t_cylinder cylinder_param);

#endif
