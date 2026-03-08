/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:31:35 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDERBONUS_H
# define CYLINDERBONUS_H

# include "material_bonus.h"
# include "vec_bonus.h"

/*
@param bottom_center center of bottom disk
*/
typedef struct s_cylinder
{
	t_hitter	hitter;
	t_point3	bottom_center;
	t_vec3		direct;
	double		radius;
	double		height;
}	t_cylinder;

t_hitter	*generate_cylinder(t_cylinder cylinder_param);

#endif
