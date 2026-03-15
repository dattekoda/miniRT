/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:33:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 19:49:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "hitter.h"
# include "material.h"

typedef struct s_sphere
{
	t_hitter	hitter;
	t_point3	center;
	double		radius;
	double		rad_squared;
}	t_sphere;

t_hitter	*generate_sphere(t_sphere shape_param);

#endif
