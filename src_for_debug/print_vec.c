/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:43:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/20 22:13:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <stdio.h>

void	print_vec3(t_vec3 v)
{
	fprintf(stderr, "vec: (%.2f, %.2f, %.2f)\n", v.e[0], v.e[1], v.e[2]);
}

void	print_vec2(t_vec2 m)
{
	fprintf(stderr, "vec: (%.2f, %.2f)\n", m.e[0], m.e[1]);
}
