/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder_disk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:33:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/17 21:01:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "vec_utils.h"

static void	add_cylinder_disk(t_list **line_list)
{
	t_list	*cur;
	t_list	*cur_next;

	cur = *line_list;
	while (cur)
	{
		if (match_identifier(cur->content, &g_cylinder_info) == SUCCESS)
		{
			cur_next = cur->next;
			cur->next = 
		}
	}
}

"cy x,y,z a,b,c diameter height r,g,b"
"di x,y,z a,b,c diameter "