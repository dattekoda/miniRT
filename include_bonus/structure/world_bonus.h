/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:27:58 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_BONUS_H
# define WORLD_BONUS_H

# include "vec_bonus.h"
# include "camera_bonus.h"
# include "libft.h"
# include "hitter_bonus.h"

typedef struct s_world
{
	t_color		ambient_light;
	t_camera	camera;
	t_list		*light_list;
	t_hitter	*object_tree;
}	t_world;

#endif
