/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_local_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:03:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/03 22:58:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <stddef.h>

t_vec3	local_normal_ripple(t_vec2 map);
t_vec3	local_normal_block(t_vec2 map);

t_color ( * const g_local_normal[])(t_vec2) ={
local_normal_ripple,
local_normal_block,
NULL
};
