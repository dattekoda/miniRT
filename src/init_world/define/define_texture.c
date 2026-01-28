/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:01:00 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 16:23:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include <stddef.h>

t_texture	*generate_solid_texture(t_color color);

const char	*g_texture_specifiers[] = {
	"solid",
	// "checker",
	// "bump",
	NULL
};

const t_generate_texture	g_gen_texture_table[] = 
{
	generate_solid_texture,
	NULL
};
