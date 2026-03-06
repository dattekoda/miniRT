/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:22:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/22 20:28:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include <stdio.h>

extern const t_option	*g_option_table[];

void	print_option(int option_flag)
{
	int	i;

	printf("option:\n");
	i = 0;
	while (g_option_table[i])
	{
		if (option_flag & g_option_table[i]->flag)
			printf("%s\n", g_option_table[i]->str);
		i++;
	}
}

