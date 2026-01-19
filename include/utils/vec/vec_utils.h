/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:55:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/19 22:08:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTILS_H
# define VEC_UTILS_H

# include "vec.h"

t_vec3	construct_vec3(double e0, double e1, double e2);
t_vec3	map_vec3(t_vec3 vec3, double (*f)(double));
t_vec3	constant_vec3(double d);
t_color	construct_color(double e0, double e1, double e2);
t_color	normalize_color(t_color raw_color);

t_vec3	negative_vec3(t_vec3 vec3);
t_vec3	add_vec3(t_vec3 lhs, t_vec3 rhs);
t_vec3	sub_vec3(t_vec3 lhs, t_vec3 rhs);
t_vec3	mul_vec3(t_vec3 lhs, t_vec3 rhs);
t_vec3	div_vec3(t_vec3 lhs, t_vec3 rhs);

t_vec3	scal_mul_vec3(t_vec3 lhs, double rhs);
t_vec3	scal_div_vec3(t_vec3 lhs, double rhs);

double	dot(t_vec3 lhs, t_vec3 rhs);
double	length_squared_vec3(t_vec3 vec3);
double	length_vec3(t_vec3 vec3);
t_vec3	normalize(t_vec3 vec3);

t_vec3	cross(t_vec3 lhs, t_vec3 rhs);

bool	inside_range(double d, t_range range);
// range.c

#endif