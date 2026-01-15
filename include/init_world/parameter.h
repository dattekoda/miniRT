/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:29:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 12:29:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETER_H
# define PARAMETER_H

# include "vec.h"

typedef struct s_sphere_param
{
	t_point3	center;
	double		radius;
	t_material	*mat_ptr;
}	t_sphere_param;

typedef struct s_plane_param
{
	t_point3	point;
	t_vec3		normal;
	t_material	*mat_ptr;
}	t_plane_param;

typedef struct s_cylinder_param
{
	t_point3	center;
	t_vec3		normal;
	double		radius;
	double		height;
	t_material	*mat_ptr;
}	t_cylinder_param;

#endif
