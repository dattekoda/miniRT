/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:41:39 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils_bonus.h"

/*
@brief change normal's orient in response to relation between
normal's direct and ray_in's direct
*/
t_vec3	orient_normal(const t_vec3 *hrec_normal, const t_vec3 *ray_in_direct)
{
	if (dot(*hrec_normal, *ray_in_direct) > 0)
		return (negative_vec3(*hrec_normal));
	return (*hrec_normal);
}
