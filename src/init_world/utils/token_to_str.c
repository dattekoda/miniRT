/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:21:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 16:10:48 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "libft.h"
#include <math.h>

t_result	token_to_str(const char *line, size_t *line_idx, char **str_ptr)
{
	*str_ptr = (char *)&line[*line_idx];
	if (ft_isspace(**str_ptr) || **str_ptr == '\0')
		*str_ptr = NULL;
	while (line[*line_idx] != '\0' || !ft_isspace(line[*line_idx]))
		(*line_idx)++;
	return (construct_result(NULL));
}
