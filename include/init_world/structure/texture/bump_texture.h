/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_texture.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:49:54 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/11 18:51:58 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUMP_TEXTURE_H
# define BUMP_TEXTURE_H

# include "texture.h"

typedef struct s_bump_texture
{
	t_texture	texture;
	t_color		color;
	t_vec3		(*local_normal)(t_vec2 map);
}	t_bump_texture;

#endif