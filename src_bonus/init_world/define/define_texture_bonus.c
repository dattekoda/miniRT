/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:01:00 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_define_bonus.h"
#include <stddef.h>

t_texture	*generate_solid_texture(t_color color);
t_texture	*generate_checker_texture(t_color color);
t_texture	*generate_bump_texture(t_color color);

const char					*g_texture_specifiers[] = {
	"solid",
	"checker",
	"bump",
	NULL
};

const t_generate_texture	g_gen_texture_table[] = {
	generate_solid_texture,
	generate_checker_texture,
	generate_bump_texture,
	NULL
};
