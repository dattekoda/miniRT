/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:54:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/11 22:36:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_DEFINE_H
# define VEC_DEFINE_H

# define COLOR_DIV 0.00392156862745098 // 1/255

/*
@brief vector
@param e[0] x, R
@param e[1] y, G
@param e[2] z, B
*/
typedef struct s_vec3
{
	double	e[3];
}	t_vec3;

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

typedef t_vec3	t_color;

#endif