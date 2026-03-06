/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:55:23 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/23 15:02:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METAL_H
# define METAL_H

# include "material.h"

typedef struct s_metal
{
	t_material	material;
	double		fuzz;
}	t_metal;

t_material	*generate_metal(t_texture *texture_ptr);

#endif