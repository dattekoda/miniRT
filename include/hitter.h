/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:38:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/11 18:34:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_H
# define HITTER_H

#include "ray.h"

typedef struct s_hrec	t_hrec;

typedef struct s_hitter
{
	int	(*hit)(void *self, t_ray ray, t_hrec *hrec, t_range range);
}	t_hitter;

struct s_hrec
{
	t_ray		ray_in;
	double		param_t;
	t_point3	point;
	t_vec3		normal;
	t_point2	texture_map;
};

#endif
