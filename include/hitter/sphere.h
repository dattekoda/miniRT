/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:33:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/03 23:37:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "hitter.h"
# include "material.h"

typedef struct s_sphere
{
	double		radius;
	t_hitter	hitter;
	t_point3	center;
}	t_sphere;

t_hitter	*generate_sphere(t_sphere shape_param);

#endif
