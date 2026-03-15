/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aabb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:21:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter_bonus.h"
#include <stdio.h>

void	print_vec3(t_vec3 v);

void	print_aabb(t_aabb aabb)
{
	printf("min:\t");
	print_vec3(aabb.min);
	printf("max:\t");
	print_vec3(aabb.max);
	printf("centroid:\t");
	print_vec3(aabb.centroid);
	return ;
}
