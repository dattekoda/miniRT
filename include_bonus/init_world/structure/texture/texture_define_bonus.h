/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_define_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:31:26 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_DEFINEBONUS_H
# define TEXTURE_DEFINEBONUS_H

# include "texture_bonus.h"

typedef t_texture					*(*t_generate_texture)(t_color color);
extern const char					*g_texture_specifiers[];
extern const t_generate_texture		g_gen_texture_table[];

#endif