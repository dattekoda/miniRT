/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hitter_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:20 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/29 23:44:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "element.h"
#include "hitter.h"
#include "result.h"
#include "cylinder.h"
#include "libft.h"

int			add_cylinder_disk(t_list **hitter_list, t_cylinder *cylinder);
static bool	has_subhitter(const t_element *element);
static int	add_sub_hitters(t_list **hitter_list, t_hitter *hitter_tmp);
static int	add_hitter(t_list **hitter_list,
						const char *line,
						t_hitter **hitter_tmp_p,
						const t_element *element);

int	add_hitter_list(t_list **hitter_list, const char *line,
		const t_element *element)
{
	t_hitter	*hitter_tmp;

	if (add_hitter(hitter_list, line, &hitter_tmp, element) == FAILURE)
		return (FAILURE);
	if (has_subhitter(element) == true)
	{
		if (add_sub_hitters(hitter_list, hitter_tmp) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	add_hitter(t_list **hitter_list,
						const char *line,
						t_hitter **hitter_tmp_p,
						const t_element *element)
{
	t_list		*list_tmp;

	if (element->line_to_hitter(hitter_tmp_p, line) == FAILURE)
		return (FAILURE);
	list_tmp = ft_lstnew(*hitter_tmp_p);
	if (!list_tmp)
		return ((*hitter_tmp_p)->clear(*hitter_tmp_p), FAILURE);
	ft_lstadd_back(hitter_list, list_tmp);
	return (SUCCESS);
}

static bool	has_subhitter(const t_element *element)
{
	return (element == g_info_table[CYLINDER]);
}

static int	add_sub_hitters(t_list **hitter_list, t_hitter *hitter_tmp)
{
	if (add_cylinder_disk(hitter_list, (t_cylinder *)hitter_tmp) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
