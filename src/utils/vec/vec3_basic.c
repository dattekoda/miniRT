/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:54:08 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/11 21:59:58 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "vec_define.h"

t_vec3	negative_vec3(t_vec3 vec3)
{
	return (construct_vec3(-vec3.e[0], -vec3.e[1], -vec3.e[2]));
}

t_vec3	add_vec3(t_vec3 lhs, t_vec3 rhs)
{
	return (construct_vec3(\
lhs.e[0] + rhs.e[0], \
lhs.e[1] + rhs.e[1], \
lhs.e[2] + rhs.e[2]));
}

t_vec3	sub_vec3(t_vec3 lhs, t_vec3 rhs)
{
	return (construct_vec3(\
lhs.e[0] - rhs.e[0], \
lhs.e[1] - rhs.e[1], \
lhs.e[2] - rhs.e[2]));
}

t_vec3	mul_vec3(t_vec3 lhs, t_vec3 rhs)
{
	return (construct_vec3(\
lhs.e[0] * rhs.e[0], \
lhs.e[1] * rhs.e[1], \
lhs.e[2] * rhs.e[2]));
}

t_vec3	div_vec3(t_vec3 lhs, t_vec3 rhs)
{
	return (construct_vec3(\
lhs.e[0] / rhs.e[0], \
lhs.e[1] / rhs.e[1], \
lhs.e[2] / rhs.e[2]));
}
