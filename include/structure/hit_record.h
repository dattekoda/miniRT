/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:37:18 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/22 19:49:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H

# include "ray.h"

typedef struct s_material	t_material;

typedef struct s_hit_record
{
	t_ray		ray_in;
	double		param_t;
	t_point3	point;
	t_vec3		normal;
	t_point2	map;
	t_material	*mat_ptr;
}	t_hrec;

#endif