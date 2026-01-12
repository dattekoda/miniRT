/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:27:58 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 22:01:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "vec.h"
# include "camera.h"
# include "tree.h"
# include "libft.h"

typedef struct s_world	t_world;

struct s_world
{
	int			option_flag;
	t_color		ambient;
	t_camera	camera;
	t_list		*light_list;
	t_tree		*object_tree;
};

#endif
