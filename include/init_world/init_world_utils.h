/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 17:38:25 by khanadat         ###   ########.fr       */
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
# include <stdbool.h>
# include <sys/types.h>

bool			match_identifier(
					const char *line, const t_element *info);
t_element_type	search_object(
					const char *line,
					const t_element *object_table[]);
t_result		token_to_value(
					const char *line, size_t *line_idx, double *d);
t_result		token_to_vec(
					const char *line, size_t *line_idx, t_vec3 *vec);
t_result		token_to_str(
					const char *line, size_t *line_idx, char **c);

t_material_idx	str_to_material_idx(const char *str);
t_texture_idx	str_to_texture_idx(const char *str);

#endif