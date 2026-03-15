/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:47:30 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 17:37:58 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "element_type.h"
#include <stdbool.h>
#include <sys/types.h>

bool			match_identifier(
					const char *line, const t_element *info);

/*
@brief if line is one member of object_table return the idx
*/
t_element_type	search_object(
	const char *line,
	const t_element *object_table[])
{
	size_t	idx;

	idx = 0;
	while (object_table[idx])
	{
		if (match_identifier(line, object_table[idx]))
			return (idx);
		idx++;
	}
	return (INVALID_ELEM);
}
