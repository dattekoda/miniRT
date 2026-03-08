/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_utils_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_UTILSBONUS_H
# define INIT_WORLD_UTILSBONUS_H

# include "init_world_define_bonus.h"
# include "element_bonus.h"
# include "vec_bonus.h"
# include "option_bonus.h"
# include "material_bonus.h"
# include "texture_bonus.h"
# include <stdbool.h>

bool			match_identifier(
					const char *line, const t_element *info);
ssize_t			search_object(
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