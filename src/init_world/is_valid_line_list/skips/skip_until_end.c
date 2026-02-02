/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_until_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:50:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 18:26:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "line_reader.h"

t_result	skip_until_end(t_line_reader *line_reader)
{
	skip_spaces(line_reader);
	if (lr_getc(line_reader) == '\0' && lr_getc(line_reader) != '\n')
		return (construct_result("invalid end"));
	return (construct_result(NULL));
}
