/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:57:56 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/24 15:03:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"
#include <stdio.h>

void	print_axis(t_axis axis);

void	print_split(const t_split *split)
{
	fprintf(stderr, "--- split ---\n");
	print_axis(split->axis);
	fprintf(stderr, "left_size:\t%zu, ", split->left_size);
	fprintf(stderr, "cost:\t%f\n", split->cost);
}
