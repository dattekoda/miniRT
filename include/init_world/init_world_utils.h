/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:32:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_UTILS_H
# define INIT_WORLD_UTILS_H

# include "init_world_define.h"
# include "element.h"
# include "vec.h"
# include "option.h"
# include "material.h"
# include "texture.h"
# include "line_reader.h"
# include <stdbool.h>

extern const t_element				*g_info_table[];
extern const t_element				*g_infinite_table[];
extern const t_element				*g_finite_table[];

extern const t_generate_texture		g_generate_textures[];
extern const t_generate_material	g_generate_materials[];

extern const t_option				*g_option_table[];

extern const char					*g_material_specifiers[];
extern const char					*g_texture_specifiers[];

extern const t_generate_material	g_gen_material_table[];
extern const t_generate_texture		g_gen_texture_table[];

bool				match_identifier(
						const char *line, const t_element *info);

t_result			token_to_value(t_line_reader *line_reader, double *d);
t_result			token_to_vec(t_line_reader *line_reader, t_vec3 *vec);
t_result			token_to_str(t_line_reader *line_reader, char **c);

enum e_mat_idx		str_to_material_idx(const char *str);
enum e_texture_idx	str_to_texture_idx(const char *str);

#endif