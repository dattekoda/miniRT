/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:00:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 13:50:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "libft.h"
#include <math.h>

t_result	token_to_value(const char *line, size_t *line_idx, double *d)
{
	char	*endptr;

	*d = ft_strtod(line + *line_idx, &endptr);
	if (endptr == line + *line_idx)
		return (construct_result("need valid numeric value"));
	*line_idx = (size_t)(endptr - line - 1);
	if (isnan(*d) || isinf(*d))
		return (construct_result("invalid value"));
	*line_idx = (size_t)(endptr - line);
	return (construct_result(NULL));
}
