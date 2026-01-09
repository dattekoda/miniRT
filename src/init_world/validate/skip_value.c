/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:10:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 00:11:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"

t_result	skip_value(const char *line, size_t *line_idx, \
t_vectype vectype, double *d)
{
	char	*endptr;

	*d = ft_strtod(line + *line_idx, &endptr);
	if (endptr == line + *line_idx)
		return (construct_result("need valid vector value"));
	*line_idx = endptr - line - 1;
	if (isnan(*d) || isinf(*d))
		return (construct_result("invalid vector value"));
	if (vectype == IS_COLOR && (*d < 0.0 || 255.0 < *d))
		return (construct_result("invalid color range"));
	*line_idx = (size_t)(endptr - line);
	return (construct_result(NULL));
}

