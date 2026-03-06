/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:21:20 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 19:37:23 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"

/*
@brief vec - 2*dot(vec,normal)normal
*/
t_vec3	reflect(t_vec3 vec, t_vec3 normal)
{
	return (sub_vec3(
			vec,
			scal_mul_vec3(
				normal,
				2 * dot(vec, normal))));
}
