/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:00:14 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 20:36:37 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_line_list(const t_list *line_list)
{
	while (line_list)
	{
		fprintf(stderr, "%s", (char *)line_list->content);
		line_list = line_list->next;
	}
	fprintf(stderr, "\n");
}
