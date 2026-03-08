/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_texture_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:49:54 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUMP_TEXTUREBONUS_H
# define BUMP_TEXTUREBONUS_H

# include "texture_bonus.h"

typedef struct s_bump_texture
{
	t_texture	texture;
	t_color		color;
	t_vec3		(*local_normal)(t_vec2 map);
}	t_bump_texture;

#endif