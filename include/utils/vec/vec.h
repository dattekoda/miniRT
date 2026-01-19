/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:28:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 21:15:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# define COLOR_DIV 0.00392156862745098 // 1/255

typedef struct s_vec3
{
	double	e[3];
}			t_vec3;

typedef t_vec3		t_color;
typedef t_vec3		t_point3;

// params for discriminant
typedef t_vec3		t_abc;

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
@param v[0] x
@param v[1] y
@param v[2] z
*/
typedef struct s_onb
{
	t_vec3	v[3];
}	t_onb;

#endif
