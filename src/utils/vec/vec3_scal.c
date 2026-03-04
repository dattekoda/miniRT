/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 22:06:23 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/04 15:37:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "vec.h"

t_vec3	scal_mul_vec3(t_vec3 lhs, double rhs)
{
	const t_vec3	result = {
		lhs.e[0] * rhs,
		lhs.e[1] * rhs,
		lhs.e[2] * rhs
	};
	return (result);
}

t_vec3	scal_div_vec3(t_vec3 lhs, double rhs)
{
	return (scal_mul_vec3(lhs, 1 / rhs));
}
