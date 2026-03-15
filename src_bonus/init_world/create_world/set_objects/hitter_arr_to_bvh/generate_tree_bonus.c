/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tree_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:39:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define_bonus.h"
#include "rt_define_bonus.h"
#include "vec_utils_bonus.h"
#include "result_bonus.h"
#include "tree_bonus.h"
#include "libft.h"
#include <stdlib.h>

t_aabb			surrounding_box(t_aabb aabb1, t_aabb aabb2);
void			clear_tree(void *s);
static t_tree	construct_tree(t_hitter *lhs, t_hitter *rhs);
static bool		hit_tree(
					const void *s,
					const t_ray *ray,
					t_hrec *hrec,
					t_range *range);

/*
@brief responsible for free lhs, rhs when malloc failed
*/
t_hitter	*generate_tree(t_hitter *lhs, t_hitter *rhs)
{
	t_tree	*node;

	if (!lhs && !rhs)
		return (NULL);
	if (!lhs)
		return (rhs);
	if (!rhs)
		return (lhs);
	node = ft_calloc(1, sizeof(t_tree));
	if (!node)
	{
		clear_free_hitter(lhs);
		clear_free_hitter(rhs);
		return (NULL);
	}
	*node = construct_tree(lhs, rhs);
	return ((t_hitter *)node);
}

static t_tree	construct_tree(t_hitter *lhs, t_hitter *rhs)
{
	t_tree	node;

	ft_bzero(&node, sizeof(t_tree));
	node.hitter.type = TREE;
	node.hitter.hit = hit_tree;
	node.hitter.clear = clear_tree;
	if (lhs->has_aabb && rhs->has_aabb)
	{
		node.hitter.has_aabb = true;
		node.hitter.aabb = surrounding_box(lhs->aabb, rhs->aabb);
	}
	node.lhs = lhs;
	node.rhs = rhs;
	return (node);
}

static bool	hit_tree(
		const void *s,
		const t_ray *ray,
		t_hrec *hrec,
		t_range *range)
{
	const t_tree	*self = s;
	bool			hit_lhs;
	bool			hit_rhs;

	if (self->hitter.has_aabb
		&& !hit_aabb(&self->hitter.aabb, ray, range))
		return (false);
	hit_lhs = self->lhs->hit(self->lhs, ray, hrec, range);
	hit_rhs = self->rhs->hit(self->rhs, ray, hrec, range);
	return (hit_lhs | hit_rhs);
}

/*
@brief not static because used at set_objects() in set_objects.c
*/
void	clear_tree(void *s)
{
	t_tree	*self;

	self = (t_tree *)s;
	if (self->lhs)
	{
		self->lhs->clear(self->lhs);
		free(self->lhs);
	}
	if (self->rhs)
	{
		self->rhs->clear(self->rhs);
		free(self->rhs);
	}
	self->lhs = NULL;
	self->rhs = NULL;
}
