/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_match_identifer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:58:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 12:11:07 by ikawamuk         ###   ########.fr       */
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
	assert(match_identifier("A 1.0", &g_ambient_info) == true);\
	assert(match_identifier("C\t ", &g_ambient_info) == true);
	assert(match_identifier("L  ", &g_ambient_info) == true);
	assert(match_identifier("sp\t0", &g_ambient_info) == true);
	return (0);
}