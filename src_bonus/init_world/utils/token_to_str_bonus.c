/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:21:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result_bonus.h"
#include "libft.h"
#include <math.h>

#include <stdio.h>
/*
@return if line + *line_idx doesn't have any token then set *str_ptr NULL
*/
t_result	token_to_str(const char *line, size_t *line_idx, char **str_ptr)
{
	*str_ptr = (char *)(line + *line_idx);
	if (**str_ptr == '\0' || **str_ptr == '\n')
	{
		*str_ptr = NULL;
		return (construct_result("there is no identifier"));
	}
	while (line[*line_idx] != '\0'
		&& (line[*line_idx]) != '\t'
		&& line[*line_idx] != ' ')
		(*line_idx)++;
	return (construct_result(NULL));
}
