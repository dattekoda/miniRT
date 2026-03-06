/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:55:10 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 11:56:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AABB_H
# define AABB_H

# include "vec.h"
# include "ray.h"
# include <stdbool.h>

typedef struct s_aabb
{
	t_point3	min;
	t_point3	max;
	t_point3	centroid;
}	t_aabb;

bool			hit_aabb(
					const t_aabb *self,
					const t_ray *ray,
					const t_vec2 *range);

#endif