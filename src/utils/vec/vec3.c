/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:11:51 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/11 22:33:38 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "vec_define.h"
#include <math.h>
#include <stddef.h>

t_vec3	construct_vec3(double e0, double e1, double e2)
{
	t_vec3	vec3;

	vec3.e[0] = e0;
	vec3.e[1] = e1;
	vec3.e[2] = e2;
	return (vec3);
}

t_vec3	map_vec3(t_vec3 vec3, double (*f)(double))
{
	vec3.e[0] = f(vec3.e[0]);
	vec3.e[1] = f(vec3.e[1]);
	vec3.e[2] = f(vec3.e[2]);
	return (vec3);
}

t_vec3	constant_vec3(double d)
{
	return (construct_vec3(d, d, d));
}

/*
@brief each params must be 0-255
*/
t_color	construct_color(double e0, double e1, double e2)
{
	return (scal_mul_vec3(construct_vec3(e0, e1, e2), COLOR_DIV));
}
