/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:53:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 17:40:14 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_UTILS_H
# define VALIDATE_UTILS_H

# include "validate_define.h"
# include "rt_utils.h"

extern const t_element_info	*g_info_table[];

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

t_result	skip_value(const char *line, size_t *line_idx, double *d);

t_result	skip_point(const char *line, size_t *line_idx);
t_result	skip_unit(const char *line, size_t *line_idx);
t_result	skip_color(const char *line, size_t *line_idx);

#endif
