/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_local_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:03:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/27 22:17:03 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <stddef.h>

t_vec3	local_normal_ripple(t_vec2 map);
t_vec3	local_normal_swirl(t_vec2 map);
t_vec3	local_normal_interface(t_vec2 map);
t_vec3	local_normal_grid(t_vec2 map);

t_color (*const g_local_normal[])(t_vec2) = {
	local_normal_ripple,
	local_normal_swirl,
	local_normal_interface,
	local_normal_grid,
	NULL
};
