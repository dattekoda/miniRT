/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:47:30 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/04 17:17:38 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include <stdbool.h>

bool			match_identifier(
					const char *line, const t_element *info);

/*
@brief if line is one member of object_table return the idx
*/
ssize_t	search_object(
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
	return (-1);
}
