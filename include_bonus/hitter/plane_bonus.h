/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:10:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANEBONUS_H
# define PLANEBONUS_H

# include "hitter_bonus.h"
# include "material_bonus.h"

typedef struct s_plane
{
	t_hitter	hitter;
	t_point3	point;
	t_vec3		normal;
}	t_plane;

t_hitter	*generate_plane(t_plane plane_param);

#endif
