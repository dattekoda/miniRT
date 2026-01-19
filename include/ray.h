/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:46:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 17:39:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec.h"

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direct;
}	t_ray;

t_ray	construct_ray(t_point3 origin, t_vec3 dir);

#endif
