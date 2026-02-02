/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:21:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/02 18:34:38 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "libft.h"
#include "line_reader.h"
#include <math.h>

t_result	token_to_str(t_line_reader *line_reader, char **str_ptr)
{
	while (ft_isspace(lr_getc(line_reader)))
		line_reader->idx++;
	*str_ptr = line_reader->line + line_reader->idx;
	if (**str_ptr == '\0')
		*str_ptr = NULL;
	while (lr_getc(line_reader) != '\0' || !ft_isspace(lr_getc(line_reader)))
		(line_reader->idx)++;
	return (construct_result(NULL));
}
