/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:35:43 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/17 22:14:12 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_arr.h"
#include "axis.h"
#include <stdbool.h>

static bool	aabb_x_compare(const void *lhs, const void *rhs);
static bool	aabb_y_compare(const void *lhs, const void *rhs);
static bool	aabb_z_compare(const void *lhs, const void *rhs);
static bool	aabb_compare(const void *lhs, const void *rhs, int axis);

t_compare	get_compare_func(t_axis axis)
{
	static const t_compare	compare_table[] = {
		aabb_x_compare,
		aabb_y_compare,
		aabb_z_compare
	};

	return (compare_table[axis]);
}

#include <stdio.h>
static bool	aabb_x_compare(const void *lhs, const void *rhs)
{
	printf("x\n");
	return (aabb_compare(lhs, rhs, 0));
}

static bool	aabb_y_compare(const void *lhs, const void *rhs)
{
	printf("y\n");
	return (aabb_compare(lhs, rhs, 1));
}

static bool	aabb_z_compare(const void *lhs, const void *rhs)
{
	printf("z\n");
	return (aabb_compare(lhs, rhs, 2));
}

static bool	aabb_compare(const void *lhs, const void *rhs, int axis)
{
	const t_hitter	**hitter_lhs = (const t_hitter **)lhs;
	const t_hitter	**hitter_rhs = (const t_hitter **)rhs;

	// fprintf(stderr, "%p\n", lhs);
	// print_hitter(*hitter_lhs);
	// fprintf(stderr, "lhs has_aabb %d\n", (*hitter_lhs)->has_aabb);
	// print_hitter(*hitter_rhs);
	if (!(*hitter_lhs)->has_aabb || !(*hitter_rhs)->has_aabb)
		return (false);
	// fprintf(stderr, "here\n");
	return ((*hitter_lhs)->aabb.centroid.e[axis] <  (*hitter_rhs)->aabb.centroid.e[axis]);
}
