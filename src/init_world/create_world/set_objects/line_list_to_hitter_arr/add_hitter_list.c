/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hitter_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:20 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 19:07:48 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "element.h"
#include "hitter.h"
#include "result.h"
#include "cylinder.h"
#include "libft.h"
#include <stdlib.h>

int			add_cylinder_disk(t_list **head, t_cylinder *cylinder);
static int	add_sub_hitters(t_list **head, t_hitter *hitter);
static int	add_hitter(t_list **head,
				t_hitter **hitter_p,
				const char *line,
				const t_element *element);

int	add_hitter_list(t_list **head, const char *line, const t_element *element)
{
	t_hitter	*hitter;

	hitter = NULL;
	if (add_hitter(head, &hitter, line, element) == FAILURE)
		return (FAILURE);
	if (element->has_sub_hitter)
	{
		if (add_sub_hitters(head, hitter) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	add_hitter(t_list **head,
						t_hitter **hitter_p,
						const char *line,
						const t_element *element)
{
	t_list	*tail;

	if (element->line_to_hitter(hitter_p, line) == FAILURE)
		return (FAILURE);
	tail = ft_lstnew(*hitter_p);
	if (!tail)
	{
		((*hitter_p))->clear(*hitter_p);
		free(*hitter_p);
		return (FAILURE);
	}
	ft_lstadd_back(head, tail);
	return (SUCCESS);
}

static int	add_sub_hitters(t_list **head, t_hitter *hitter)
{
	if (hitter->type == CYLINDER)
	{
		if (add_cylinder_disk(head, (t_cylinder *)hitter) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
