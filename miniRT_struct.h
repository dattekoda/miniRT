/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:03:34 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 11:53:39 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef enum	e__type {
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER	
}	e_type;

typedef struct	s_data {
	e_type	type;
	t_coord	*coord;
	t_vec	*vec;
	t_color	*color;
}	t_data;

#endif