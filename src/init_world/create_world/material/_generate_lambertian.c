/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _generate_lambertian.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:27:36 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 18:34:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"
#include "rt_utils.h"

t_material	*generate_lambertian(t_texture *texture_ptr)
{
	t_lambertian	*lambertian_ptr;

	if (!texture_ptr)
		return (NULL);
	lambertian_ptr = ft_calloc(1, sizeof(t_lambertian));
	if (!lambertian_ptr)
	{
		texture_ptr->clear(texture_ptr);
		return (NULL);
	}
	*lambertian_ptr = construct_lambertian(texture_ptr);
	return ((t_material *)lambertian_ptr);
}

static t_lambertian	construct_lambertian(t_texture *texture_ptr)
{
	t_lambertian	lambertian;

	ft_bzero(&lambertian, sizeof(t_lambertian));
	lambertian.material.scatter = scallter_lambertian;
	lambertian.material.clear = clear_material;
	lambertian.material.texture_ptr = texture_ptr;
	return (lambertian);
}
