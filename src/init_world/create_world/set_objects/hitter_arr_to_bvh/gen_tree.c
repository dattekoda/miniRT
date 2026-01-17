/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:39:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 21:42:02 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "result.h"
#include "tree.h"
#include "libft.h"

static t_tree	construct_tree(t_hitter *lhs, t_hitter *rhs);
static int		hit_tree(void *s, t_ray ray, t_hrec *hrec, t_range range);
void			clear_tree(void *s);

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
}

static int	hit_tree(void *s, t_ray ray, t_hrec *hrec, t_range range)
{
	const t_tree	*self;

	self = s;
	if (self->)
	return (SUCCESS);
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
