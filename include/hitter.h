/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:38:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 23:45:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_H
# define HITTER_H

# include "ray.h"
# include <stdbool.h>

typedef struct s_material t_material;

typedef struct s_hrec
{
	t_ray		ray_in;
	double		param_t;
	t_point3	point;
	t_vec3		normal;
	t_point2	map;
	t_material	*mat_p;
}	t_hrec;

typedef bool	(*t_hit)(const void *self, t_ray ray, t_hrec *hrec, t_range range);
typedef void	(*t_clear)(void *self);

typedef struct s_aabb
{
	t_point3	min;
	t_point3	max;
	t_point3	centroid;
	t_hit		hit;
}	t_aabb;

typedef struct s_hitter
{
	t_hit		hit;
	t_clear		clear;
	bool		has_aabb;
	t_aabb		aabb;
	t_material	*mat_ptr;
}	t_hitter;

#endif
