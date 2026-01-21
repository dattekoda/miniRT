/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:21:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/21 16:16:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "libft.h"
#include <math.h>

t_result	token_to_char(const char *line, size_t *line_idx, char *c)
{
	*c = line[(*line_idx)];
	if (*c == '\0' || ft_isspace(*c))
		return (construct_result("invalid value"));
	(*line_idx)++;
	return (construct_result(NULL));
}
