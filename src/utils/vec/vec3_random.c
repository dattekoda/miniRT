/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:58:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:34:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "rt_utils.h"

t_vec3	construct_vec3(double e0, double e1, double e2);
double	length_squared_vec3(t_vec3 vec3);

t_vec3	random_in_unit_disk(void)
{
	t_vec3	p;

	while (1)
	{
		p = construct_vec3(random_double(-1, 1), random_double(-1, 1), 0);
		if (length_squared_vec3(p) >= 1)
			continue ;
		return (p);
	}
}
