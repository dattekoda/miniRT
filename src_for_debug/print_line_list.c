/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:00:14 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/11 19:44:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_line_list(const t_list *line_list)
{
	t_list	*cur = (t_list *)line_list;
	while (cur)
	{
		printf("%s", (char *)cur->content);
		cur = cur->next;
	}
	printf("\n");
}
