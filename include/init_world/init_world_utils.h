/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 21:00:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_UTILS_H
# define INIT_WORLD_UTILS_H

# include "element.h"
# include "vec.h"
# include "option.h"
# include "init_world_define.h"
# include <stdbool.h>

extern const t_element				*g_info_table[];
extern const t_element				*g_infinite_table[];
extern const t_element				*g_finite_table[];

extern const t_generate_texture		g_generate_textures[];
extern const t_generate_material	g_generate_materials[];

extern const t_option				*g_option_table[];

bool		match_identifier(const char *line, const t_element *info);

t_result	token_to_value(const char *line, size_t *line_idx, double *d);
t_result	token_to_vec(const char *line, size_t *line_idx, t_vec3 *vec);
t_result	token_to_char(const char *line, size_t *line_idx, char *c);

size_t	char_to_material_idx(char c, size_t default_idx);
size_t	char_to_texture_idx(char c, size_t default_idx);

#endif
