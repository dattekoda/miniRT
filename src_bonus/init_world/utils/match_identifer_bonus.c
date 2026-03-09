/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_identifer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:37:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_bonus.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

// typedef struct s_elam {
// 	char	*id;
// 	size_t	id_len;
// }	t_element;

bool	match_identifier(const char *line, const t_element *info)
{
	if (ft_strncmp(line, info->id, info->id_len))
		return (false);
	if (ft_strchr(" \t", line[info->id_len]) == NULL)
		return (false);
	return (true);
}

// int	main(void) {
// 	t_element	co = {"co", 2};
// 	t_element	__CHAR16_TYPE__
// }
