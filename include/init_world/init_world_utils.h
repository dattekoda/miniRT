/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:24:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_UTILS_H
# define INIT_WORLD_UTILS_H

# include "element.h"
# include "vec.h"

extern const t_element	g_ambient_info;
extern const t_element	g_camera_info;
extern const t_element	g_light_info;
extern const t_element	*g_info_table[];
extern const t_element	*g_infinite_table[];
extern const t_element	*g_finite_table[];

int			match_identifier(const char *line, const t_element *info);
void		clear_hitter(void *content);
t_result	token_to_value(const char *line, size_t *line_idx, double *d);
t_result	token_to_vec(const char *line, size_t *line_idx, t_vec3 *vec);

#endif
