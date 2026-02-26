/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_axis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:48 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/24 15:03:15 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "axis.h"
#include <stdio.h>

void	print_axis(t_axis axis)
{
	fprintf(stderr, "axis:\t");
	if (axis == A_X)
		fprintf(stderr, "x");
	if (axis == A_Y)
		fprintf(stderr, "y");
	if (axis == A_Z)
		fprintf(stderr, "z");
	fprintf(stderr, ", ");
}
