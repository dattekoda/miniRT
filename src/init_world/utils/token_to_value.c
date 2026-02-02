/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:00:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:32:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "libft.h"
#include "line_reader.h"
#include <math.h>

t_result	token_to_value(t_line_reader *line_reader, double *d)
{
	char	*endptr;

	*d = ft_strtod(line_reader->line + line_reader->idx, &endptr);
	if (endptr == line_reader->line + line_reader->idx)
		return (construct_result("need valid numeric value"));
	line_reader->idx = (size_t)(endptr - line_reader->line - 1);
	if (isnan(*d) || isinf(*d))
		return (construct_result("invalid value"));
	line_reader->idx = (size_t)(endptr - line_reader->line);
	return (construct_result(NULL));
}
