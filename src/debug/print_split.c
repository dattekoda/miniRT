/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:57:56 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 20:48:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"
#include <stdio.h>

void	print_axis(t_axis axis);

void	print_split(const t_split *split)
{
	printf("--- split ---\n");
	print_axis(split->axis);
	printf("left_size:\t%zu, ", split->left_size);
	printf("cost:\t%f\n", split->cost);
}
