/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:53:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/15 13:45:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_UTILS_H
# define VALIDATE_UTILS_H

# include "result.h"
# include "vec.h"
# include <stddef.h>

void		err_point_out(char *line, size_t err_idx);
t_result	skip_spaces(const char *line, size_t *line_idx);

#endif
