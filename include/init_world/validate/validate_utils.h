/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:53:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/12 16:23:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_UTILS_H
# define VALIDATE_UTILS_H

# include "result.h"

t_result	construct_result(char *_err_msg);
void		err_point_out(char *line, size_t err_idx);

t_result	skip_spaces(const char *line, size_t *line_idx);
t_result	skip_until_end(const char *line, size_t *line_idx);

t_result	skip_range(const char *line, size_t *line_idx, \
double min, double max);
t_result	skip_lighting_ratio(const char *line, size_t *line_idx);
t_result	skip_angle(const char *line, size_t *line_idx);
t_result	skip_sharp_angle(const char *line, size_t *line_idx);
t_result	skip_length(const char *line, size_t *line_idx);

t_result	token_to_value(const char *line, size_t *line_idx, double *d);
t_result	token_to_vec(const char *line, size_t *line_idx, double d3[3]);

t_result	skip_point(const char *line, size_t *line_idx);
t_result	skip_unit(const char *line, size_t *line_idx);
t_result	skip_color(const char *line, size_t *line_idx);

#endif
