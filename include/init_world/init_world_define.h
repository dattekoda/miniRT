/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/20 19:55:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_DEFINE_H
# define INIT_WORLD_DEFINE_H

# define T_AABB	1.0f
# define T_TRI	1.0f

# define PATHTRACING_LIGHT_STRENGTH 100

enum e_option
{
	IS_PHONG = (1 << 0)
};

typedef void *(*t_generate_texture)(void *arg);

#endif