/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:21:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 15:09:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "libft.h"
#include <math.h>

t_result	token_to_str(const char *line, size_t *line_idx, char **str_p)
{
	*str_p = &line[*line_idx];
	if (!**str_p)
		*str_p = NULL;
	while (line[*line_idx] != '\0' || !ft_isspace(line[*line_idx]))
		(*line_idx)++;
	return (construct_result(NULL));
}
