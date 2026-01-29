/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:21:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/29 20:25:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "libft.h"
#include <math.h>

t_result	token_to_str(const char *line, size_t *line_idx, char **str_ptr)
{
	while (ft_isspace(line[*line_idx]))
		(*line_idx)++;
	*str_ptr = (char *)&line[*line_idx];
	if (**str_ptr == '\0')
		*str_ptr = NULL;
	while (line[*line_idx] != '\0' || !ft_isspace(line[*line_idx]))
		(*line_idx)++;
	return (construct_result(NULL));
}
