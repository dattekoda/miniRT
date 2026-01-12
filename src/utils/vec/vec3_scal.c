/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 22:06:23 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/11 22:35:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "vec_define.h"

t_vec3	scal_mul_vec3(t_vec3 lhs, double rhs)
{
	return (construct_vec3(\
lhs.e[0] * rhs, \
lhs.e[1] * rhs, \
lhs.e[2] * rhs));
}

t_vec3	scal_div_vec3(t_vec3 lhs, double rhs)
{
	return (scal_mul_vec3(lhs, 1 / rhs));
}
