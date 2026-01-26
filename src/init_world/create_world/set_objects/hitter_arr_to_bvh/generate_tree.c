/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:39:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 23:19:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "result.h"
#include "tree.h"
#include "libft.h"
#include <stdlib.h>

static t_tree	construct_tree(t_hitter *lhs, t_hitter *rhs);
static bool		hit_tree
	(const void *s, const t_ray *ray, t_hrec *hrec, t_range *range);
void			clear_tree(void *s);

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
		lhs->clear(lhs);
		rhs->clear(rhs);
		return (NULL);
	}
	*node = construct_tree(lhs, rhs);
	return ((t_hitter *)node);
}

static t_tree	construct_tree(t_hitter *lhs, t_hitter *rhs)
{
	t_tree	node;

	ft_bzero(&node, sizeof(t_tree));
	node.hitter.hit = hit_tree;
	node.hitter.clear = clear_tree;
	node.lhs = lhs;
	node.rhs = rhs;
	return (node);
}

static bool	hit_tree(const void *s, const t_ray *ray, t_hrec *hrec, t_range *range)
{
	const t_tree	*self;
	bool			hit_lhs;
	bool			hit_rhs;

	self = s;
	if (self->hitter.has_aabb
		&& !self->hitter.aabb.hit(&self->hitter.aabb, ray, hrec, range))
		return (false);
	hit_lhs = self->lhs->hit(self->lhs, ray, hrec, range);
	if (hit_lhs)
		range->e[1] = hrec->param_t;
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
		self->lhs->clear(self->lhs);
	if (self->rhs)
		self->rhs->clear(self->rhs);
	self->lhs = NULL;
	self->rhs = NULL;
	free(self);
}
