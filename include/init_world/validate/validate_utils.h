/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:53:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/02 18:28:56 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_UTILS_H
# define VALIDATE_UTILS_H

# include "result.h"
# include "vec.h"
# include "line_reader.h"
# include <stddef.h>

void		err_point_out(t_line_reader *line_reader);
t_result	skip_spaces(t_line_reader *line_reader);

#endif
