/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_hitter_list_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:04:27 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils_bonus.h"
#include "hitter_list_bonus.h"
#include "element_bonus.h"
#include "libft.h"
#include <stdlib.h>

int						line_list_to_hitter_list(
							t_list **hitter_list,
							const t_list *line_list,
							const t_element *object_table[]);
static t_hitter_list	construct_hitter_list(t_list *list);
static bool				hit_hitter_list(
							const void *s,
							const t_ray *ray,
							t_hrec *hrec,
							t_range *range);
static void				clear_hitter_list(void *s);

t_hitter	*generate_hitter_list(
				const t_list *line_list,
				const t_element *object_table[])
{
	t_hitter_list	*hitter_list;
	t_list			*head;

	if (!line_list)
		return (NULL);
	hitter_list = ft_calloc(1, sizeof(t_hitter_list));
	if (!hitter_list)
		return (NULL);
	head = NULL;
	if (line_list_to_hitter_list(&head, line_list, object_table) == FAILURE)
	{
		free(hitter_list);
		return (NULL);
	}
	*hitter_list = construct_hitter_list(head);
	return ((t_hitter *)hitter_list);
}

static t_hitter_list	construct_hitter_list(t_list *head)
{
	t_hitter_list	hitter_list;

	ft_bzero(&hitter_list, sizeof(t_hitter_list));
	hitter_list.hitter.type = LIST;
	hitter_list.hitter.hit = hit_hitter_list;
	hitter_list.hitter.clear = clear_hitter_list;
	hitter_list.head = head;
	return (hitter_list);
}

static bool	hit_hitter_list(
		const void *s,
		const t_ray *ray,
		t_hrec *hrec,
		t_range *range)
{
	const t_list		*cur = ((t_hitter_list *)s)->head;
	bool				is_hit;

	is_hit = false;
	while (cur)
	{
		if (((t_hitter *)cur->content)->hit(cur->content, ray, hrec, range))
			is_hit = true;
		cur = cur->next;
	}
	return (is_hit);
}

static void	clear_hitter_list(void *s)
{
	ft_lstclear(&(((t_hitter_list *)s)->head), clear_free_hitter);
	return ;
}
