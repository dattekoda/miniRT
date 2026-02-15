/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_component_lower.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:20:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 21:24:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "axis.h"
#include "hitter.h"
#include <assert.h>

bool	is_component_lower(const t_hitter *subject, const t_hitter *base,
		int axis);

void	test_is_component_lower(void)
{
	const t_hitter a = {.has_aabb = true, .aabb = {
		.centroid = {0.0, 1.0, 2.0}
	}};
	const t_hitter b = {.has_aabb = true, .aabb = {
		.centroid = {2.0, 1.0, 0.0}
	}};
	assert(is_component_lower(&a, &b, X) == true);
	assert(is_component_lower(&a, &b, Y) == false);
	assert(is_component_lower(&a, &b, Z) == false);
}


