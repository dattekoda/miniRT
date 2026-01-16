/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_product.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 22:05:29 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/16 15:10:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "vec.h"
#include <math.h>

double	dot(t_vec3 lhs, t_vec3 rhs)
{
	return (lhs.e[0] * rhs.e[0] \
+ lhs.e[1] * rhs.e[1] \
+ lhs.e[2] * rhs.e[2]);
}

double	length_squared_vec3(t_vec3 vec3)
{
	return (dot(vec3, vec3));
}

double	length_vec3(t_vec3 vec3)
{
	return (sqrt(length_squared_vec3(vec3)));
}

t_vec3	normalize(t_vec3 vec3)
{
	return (scal_div_vec3(vec3, length_vec3(vec3)));
}

/*
@brief
(l1 * r2 - l2 * r1, 
l2 * r0 - l0 * r2, 
l0 * r1 - l1 * r2)
*/
t_vec3	cross(t_vec3 lhs, t_vec3 rhs)
{
	return (construct_vec3(\
lhs.e[1] * rhs.e[2] - lhs.e[2] * rhs.e[1], \
lhs.e[2] * rhs.e[0] - lhs.e[0] * rhs.e[2], \
lhs.e[0] * rhs.e[1] - lhs.e[1] * rhs.e[0]\
));
}
