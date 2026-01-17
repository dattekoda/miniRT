/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:45:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 16:59:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_TEXTURE_H
# define SOLID_TEXTURE_H

# include "texture.h"
# include "vec.h"

typedef struct s_solid_texture
{
	t_texture	texture;
	t_color		color;
}	t_solid_texture;

t_solid_texture	*gen_solid_texture(t_color color);

#endif
