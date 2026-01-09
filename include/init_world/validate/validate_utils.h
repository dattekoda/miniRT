/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:53:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 00:22:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_UTILS_H
# define VALIDATE_UTILS_H

# include "validate_define.h"

extern const t_element_info	*info_table[];

t_result	construct_result(char *_err_msg);

t_result	skip_spaces(const char *line, size_t *line_idx);
t_result	skip_until_end(const char *line, size_t *line_idx);

t_result	skip_lighting_ratio(const char *line, size_t *line_idx);
t_result	skip_fov(const char *line, size_t *line_idx);
t_result	skip_diameter(const char *line, size_t *line_idx);
t_result	skip_value(const char *line, size_t *line_idx, \
t_vectype vectype, double *d);

#endif