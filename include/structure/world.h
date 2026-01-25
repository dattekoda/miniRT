/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:27:58 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 02:00:29 by ikawamuk         ###   ########.fr       */
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
	int			option_flag;
	t_color		ambient;
	t_camera	camera;
	t_list		*light_list;
	t_hitter	*object_tree;
}	t_world;

#endif
