/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:43:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_bonus.h"
#include <stdio.h>

void	print_vec3(t_vec3 v)
{
	printf("vec:\t(%.2f, %.2f, %.2f)\n", v.e[0], v.e[1], v.e[2]);
}

void	print_vec2(t_vec2 m)
{
	printf("vec:\t(%.2f, %.2f)\n", m.e[0], m.e[1]);
}
