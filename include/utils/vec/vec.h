/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:28:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 23:29:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# define COLOR_DIV 0.00392156862745098 // 1/255

/*
@param e[0] X
@param e[1] Y
@param e[2] Z
*/
typedef struct s_vec3
{
	double	e[3];
}			t_vec3;

/*
@param e[0] R
@param e[1] G
@param e[2] B
*/
typedef t_vec3		t_color;

/*
@param e[0] X
@param e[1] Y
@param e[2] Z
*/
typedef t_vec3		t_point3;

typedef struct s_vec2
{
	double	e[2];
}	t_vec2;

typedef t_vec2		t_point2;

/*
@param e[0] min
@param e[1] max
*/
typedef t_point2	t_range;

/*
@brief orthonormal basis
@param v[0] u
@param v[1] v
@param v[2] w: up
*/
typedef struct s_onb
{
	t_vec3	v[3];
}	t_onb;

#endif
