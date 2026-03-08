/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:53:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_UTILSBONUS_H
# define VALIDATE_UTILSBONUS_H

# include "result_bonus.h"
# include "vec_bonus.h"
# include <stddef.h>

void		err_point_out(char *line, size_t err_idx);
t_result	skip_spaces(const char *line, size_t *line_idx);

#endif
