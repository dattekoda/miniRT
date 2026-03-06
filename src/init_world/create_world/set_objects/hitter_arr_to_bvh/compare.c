/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:35:43 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 19:13:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "axis.h"

static int	aabb_x_compare(const void *lhs, const void *rhs);
static int	aabb_y_compare(const void *lhs, const void *rhs);
static int	aabb_z_compare(const void *lhs, const void *rhs);
static int	aabb_compare(const void *lhs, const void *rhs, int axis);

t_compar	get_compar_func(t_axis axis)
{
	static const t_compar	compare_table[] = {
		aabb_x_compare,
		aabb_y_compare,
		aabb_z_compare
	};

	return (compare_table[axis]);
}

static int	aabb_x_compare(const void *lhs, const void *rhs)
{
	return (aabb_compare(lhs, rhs, A_X));
}

static int	aabb_y_compare(const void *lhs, const void *rhs)
{
	return (aabb_compare(lhs, rhs, A_Y));
}

static int	aabb_z_compare(const void *lhs, const void *rhs)
{
	return (aabb_compare(lhs, rhs, A_Z));
}

static int	aabb_compare(const void *lhs, const void *rhs, int axis)
{
	const t_hitter	**hitter_lhs = (const t_hitter **)lhs;
	const t_hitter	**hitter_rhs = (const t_hitter **)rhs;

	if (!(*hitter_lhs)->has_aabb || !(*hitter_rhs)->has_aabb)
		return (0);
	if ((*hitter_lhs)->aabb.centroid.e[axis]
		== (*hitter_rhs)->aabb.centroid.e[axis])
		return (0);
	if ((*hitter_lhs)->aabb.centroid.e[axis]
		< (*hitter_rhs)->aabb.centroid.e[axis])
		return (-1);
	return (1);
}
