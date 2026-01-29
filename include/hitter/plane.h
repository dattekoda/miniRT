/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:10:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/29 22:12:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "hitter.h"
# include "material.h"

typedef struct s_plane
{
	t_hitter	hitter;
	t_point3	point;
	t_vec3		normal;
}	t_plane;

t_hitter	*generate_plane(t_plane plane_param);

#endif
