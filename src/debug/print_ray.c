/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:28:35 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 20:28:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "rt_debug.h"
#include <stdio.h>

void	print_ray(const t_ray *ray)
{
	fprintf(stderr, "\n");
	if (!ray)
	{
		fprintf(stderr, "ray: null\n");
		return ;
	}
	fprintf(stderr, "ray: origin\n");
	print_vec3(ray->origin);
	fprintf(stderr, "ray: direct\n");
	print_vec3(ray->direct);
}
