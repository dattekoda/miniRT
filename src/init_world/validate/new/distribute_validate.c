/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:34:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 16:42:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "libft.h"
#include <stddef.h>

typedef struct s_key
{
	char			*identifiler;
	size_t			identifier_len;
	t_element_type	type;
}	t_key;

const s_key	key_list[2] = {
	{"A", 1, AMBIENT}, NULL
}

int	distribute_validate(char *line)
{
	if (ft_strncmp(line, g_elem_table[i].))
}

t_element_type	get_element_type(char *line)
{
	size_t	i;

	i = 0;
	while (key_list[i] != NULL)
	{
		if (strncmp(line, key_list[i].identifier, key_list[i].identifier_len) == 0)
			return (key_list[i].type);
	}
	return (NOTHING);
}