/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:00:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:30:26 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "validate_utils.h"
#include "vec.h"
#include "libft.h"
#include "line_reader.h"

static t_result	skip_comma(t_line_reader *line_reader);

t_result	token_to_vec(t_line_reader *line_reader, t_vec3 *vec)
{
	t_result	result;
	size_t		e_idx;

	e_idx = 0;
	while (e_idx < 3)
	{
		result = token_to_value(line_reader, &vec->e[e_idx]);
		if (result.state == FAILURE)
			return (result);
		if (e_idx != 2)
			result = skip_comma(line_reader);
		if (result.state == FAILURE)
			return (result);
		e_idx++;
	}
	return (construct_result(NULL));
}

static t_result	skip_comma(t_line_reader *line_reader)
{
	skip_spaces(line_reader);
	if (lr_getc(line_reader) != ',')
		return (construct_result("need ','"));
	(line_reader->idx)++;
	return (construct_result(NULL));
}
