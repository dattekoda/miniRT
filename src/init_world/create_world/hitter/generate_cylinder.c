/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:07:16 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/20 17:13:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_hitter	*generate_cylinder(t_cylinder cylinder_param, t_material *mat_ptr)
{
	t_cylinder	*p;

	if (!mat_ptr)
		return (NULL);
	p = ft_calloc(1, sizeof(t_cylinder));
	if (!p)
		return (mat_ptr->clear(mat_ptr), NULL);
	*p = construct_cylinder(cylinder_param, mat_ptr);
	return ((t_hitter *)p);
}
