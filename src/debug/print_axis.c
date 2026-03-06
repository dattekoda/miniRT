/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_axis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:48 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 20:48:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "axis.h"
#include <stdio.h>

void	print_axis(t_axis axis)
{
	printf("axis:\t");
	if (axis == A_X)
		printf("x");
	if (axis == A_Y)
		printf("y");
	if (axis == A_Z)
		printf("z");
	printf(", ");
}
