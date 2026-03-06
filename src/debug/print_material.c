/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:27:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 20:48:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_define.h"
#include <stdio.h>

void	print_material(const t_material *material)
{
	if (!material)
	{
		printf("material null\n");
		return ;
	}
	printf("material: %s\n", g_material_specifiers[material->idx]);
}
