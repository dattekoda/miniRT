/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:27:58 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLDBONUS_H
# define WORLDBONUS_H

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
