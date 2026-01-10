/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:10:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 16:11:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "libft.h"
#include <math.h>

t_result	skip_value(const char *line, size_t *line_idx, \
t_vectype vectype, double *d)
{
	char	*endptr;

	*d = ft_strtod(line + *line_idx, &endptr);
	if (endptr == line + *line_idx)
		return (construct_result("need valid value"));
	*line_idx = (size_t)(endptr - line - 1);
	if (isnan(*d) || isinf(*d))
		return (construct_result("invalid value"));
	if (vectype == IS_COLOR && (*d < 0.0 || 255.0 < *d))
		return (construct_result("invalid color range"));
	*line_idx = (size_t)(endptr - line);
	return (construct_result(NULL));
}
