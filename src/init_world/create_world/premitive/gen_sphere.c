/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:55:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 15:51:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameter.h"
#include "sphere.h"
#include "init_world_utils.h"
#include "libft.h"

t_sphere	*gen_sphere(t_sphere_param *param)
{
	t_sphere	*p;
	t_material	*mat_p;
	t_texture	*texture_p;

	
	texture_p = g_gen_textures[g_]
	
	mat_p = gen_lambertian();
	if (!mat_p)
	{
		texture_p->clear(texture_p);
		return (NULL);
	}
	p = ft_calloc(1, sizeof(t_sphere));
	if (!p)
	{
		mat_p->clear(mat_p);
		return (NULL);
	}
	*p = construct_sphere(param);
	return (p);
}

static t_sphere	construct_sphere(t_sphere_param *param)
{
	t_sphere	sphere;

	sphere.center = param->center;
	sphere.radius = param->radius;
	
	return (sphere);
}
