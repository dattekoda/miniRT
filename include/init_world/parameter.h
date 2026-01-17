/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:29:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 20:13:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETER_H
# define PARAMETER_H

# include "vec.h"
# include "material.h"

typedef struct s_sphere_param
{
	t_point3	center;
	double		radius;
}	t_sphere_param;

typedef struct s_plane_param
{
	t_point3	point;
	t_vec3		normal;
}	t_plane_param;

typedef struct s_cylinder_param
{
	t_point3	center;
	t_vec3		normal;
	double		radius;
	double		height;
}	t_cylinder_param;

#endif
