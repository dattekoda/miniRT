/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_match_identifer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:58:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 19:35:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include <assert.h>

bool	match_identifier(const char *line, const t_element *info);

extern const t_element				g_ambient_info;
extern const t_element				g_camera_info;
extern const t_element				g_light_info;
extern const t_element				g_sphere_info;

int	test_match_identifer(void)
{
	assert(match_identifier("A 1.0", g_info_table[AMBIENT]) == true);
	assert(match_identifier("C\t ", g_info_table[CAMERA]) == true);
	assert(match_identifier("L  ", g_info_table[LIGHT]) == true);
	assert(match_identifier("sp\t0", g_info_table[SPHERE]) == true);
	return (0);
}