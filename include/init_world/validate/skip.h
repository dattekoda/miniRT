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

#ifndef SKIP_H
# define SKIP_H

# include "result.h"
# include "line_reader.h"
# include <stddef.h>

typedef t_result		(*t_skip)(t_line_reader *line_reader);

t_result	skip_lighting_ratio(t_line_reader *line_reader);
t_result	skip_angle(t_line_reader *line_reader);
t_result	skip_sharp_angle(t_line_reader *line_reader);
t_result	skip_length(t_line_reader *line_reader);

t_result	skip_point(t_line_reader *line_reader);
t_result	skip_unit(t_line_reader *line_reader);
t_result	skip_color(t_line_reader *line_reader);

t_result	skip_until_end(t_line_reader *line_reader);

#endif
