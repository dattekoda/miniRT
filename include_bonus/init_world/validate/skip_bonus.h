/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:53:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 12:57:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKIPBONUS_H
# define SKIPBONUS_H

# include "result_bonus.h"
# include <stddef.h>

typedef t_result		(*t_skip)(const char *line, size_t *line_idx);

t_result	skip_lighting_ratio(const char *line, size_t *line_idx);
t_result	skip_angle(const char *line, size_t *line_idx);
t_result	skip_sharp_angle(const char *line, size_t *line_idx);
t_result	skip_length(const char *line, size_t *line_idx);

t_result	skip_point(const char *line, size_t *line_idx);
t_result	skip_unit(const char *line, size_t *line_idx);
t_result	skip_color(const char *line, size_t *line_idx);

t_result	skip_until_end(const char *line, size_t *line_idx);

#endif
