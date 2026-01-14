/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tree_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:39:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 00:06:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "tree.h"
#include "libft.h"

static t_tree	construct_tree(t_hitter *lhs, t_hitter *rhs);
static int	hit_bvh(void *s, t_ray ray, t_hrec *hrec, t_range range);
static void	clear_bvh(void *s);

t_hitter	*gen_tree(t_hitter *lhs, t_hitter *rhs)
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
		return (NULL);
	*node = construct_tree(lhs, rhs);
	return ((t_hitter *)node);
}

static t_tree	construct_tree(t_hitter *lhs, t_hitter *rhs)
{
	t_tree	node;

	ft_bzero(&node, sizeof(t_tree));
	node.hitter.hit = hit_bvh;
	node.hitter.clear = clear_bvh;
	node.lhs = lhs;
	node.rhs = rhs;
}

static int	hit_bvh(void *s, t_ray ray, t_hrec *hrec, t_range range)
{
	const t_tree	*self;

	self = s;
	// if ()
	return (SUCCESS);
}

static void	clear_bvh(void *s)
{
	t_tree	*self;

	self = s;
	if (self->lhs)
		self->lhs->clear(self->lhs);
	if (self->rhs)
		self->rhs->clear(self->rhs);
	self->lhs = NULL;
	self->rhs = NULL;
	free(self);
}
