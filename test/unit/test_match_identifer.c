/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_match_identifer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:58:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 14:44:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "element.h"
#include <assert.h>

bool	match_identifier(const char *line, const t_element *info);

int	test_match_identifer(void)
{
	assert(match_identifier("A 1.0", g_element_table[AMBIENT]) == true);
	assert(match_identifier("C\t ", g_element_table[CAMERA]) == true);
	assert(match_identifier("L  ", g_element_table[LIGHT]) == true);
	assert(match_identifier("sp\t0", g_element_table[SPHERE]) == true);
	return (0);
}