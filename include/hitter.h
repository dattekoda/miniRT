/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:38:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:56:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_H
# define HITTER_H

# include "ray.h"

typedef struct s_hrec
{
	t_ray		ray_in;
	double		param_t;
	t_point3	point;
	t_vec3		normal;
	t_point2	texture_map;
}	t_hrec;

typedef struct s_aabb
{
	t_point3	min;
	t_point3	max;
	t_point3	centroid;
	int			(*hit)(void *self, t_ray ray, t_hrec *hrec, t_range range);
}	t_aabb;

typedef struct s_hitter
{
	int		(*hit)(void *self, t_ray ray, t_hrec *hrec, t_range range);
	void	(*clear)(struct s_hitter *self);
	int		has_aabb;
	t_aabb	aabb;
}	t_hitter;

#endif
