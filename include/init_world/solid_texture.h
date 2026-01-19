/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:45:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 18:21:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_TEXTURE_H
# define SOLID_TEXTURE_H

# include "texture.h"
# include "vec.h"

/*
@brief solid, bump, checker
*/
typedef struct s_solid_texture
{
	t_texture	texture;
	t_color		color;
}	t_solid_texture;

t_solid_texture	*generate_solid_texture(t_color color);

#endif
