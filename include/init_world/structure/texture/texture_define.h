/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:31:26 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/22 19:32:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_DEFINE_H
# define TEXTURE_DEFINE_H

# include "texture.h"

typedef t_texture					*(*t_generate_texture)(t_color color);
extern const char					*g_texture_specifiers[];
extern const t_generate_texture		g_gen_texture_table[];

#endif