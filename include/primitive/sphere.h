/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:33:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 15:52:16 by ikawamuk         ###   ########.fr       */
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
}	t_sphere;

t_sphere	*gen_sphere(t_sphere *shape_param, t_material *mat_p);

#endif
