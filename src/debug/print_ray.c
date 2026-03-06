/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:28:35 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 20:48:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "rt_debug.h"
#include <stdio.h>

void	print_ray(const t_ray *ray)
{
	printf("\n");
	if (!ray)
	{
		printf("ray: null\n");
		return ;
	}
	printf("ray: origin\n");
	print_vec3(ray->origin);
	printf("ray: direct\n");
	print_vec3(ray->direct);
}
