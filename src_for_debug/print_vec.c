/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:43:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/12 20:18:00 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <stdio.h>

void	print_vec3(t_vec3 v)
{
	fprintf(stderr, "(");
	for (int i = 0; i < 3; i++)
	{
		fprintf(stderr, "%f", v.e[i]);
		if (i != 2)
			fprintf(stderr, ", ");
	}
	fprintf(stderr, ")\n");
	// for (int i = 0; i < 3; i++)
	// 	fprintf(stderr, "e[%d]: %f\n", i, v.e[i]);
}

void	print_vec2(t_vec2 v)
{
	fprintf(stderr, "(");
	for (int i = 0; i < 2; i++)
	{
		fprintf(stderr, "%f", v.e[i]);
		if (i != 1)
			fprintf(stderr, ", ");
	}
	fprintf(stderr, ")\n");
}
