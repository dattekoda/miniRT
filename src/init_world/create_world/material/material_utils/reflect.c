/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:26:36 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/09 18:50:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"

/*
@brief vec - 2*dot(vec,normal)normal
*/
t_vec3	reflect(const t_vec3 *vec, const t_vec3 *normal)
{
	return (sub_vec3(
		*vec,
		scal_mul_vec3(
			*normal,
			2 * dot(*vec, *normal))));
}
