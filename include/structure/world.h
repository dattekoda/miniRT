/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:27:58 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/07 21:12:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "vec.h"
# include "camera.h"
# include "libft.h"
# include "hitter.h"

typedef struct s_world
{
	t_color		ambient_light;
	t_camera	camera;
	t_list		*light_list;
	t_hitter	*object_tree;
}	t_world;

#endif
