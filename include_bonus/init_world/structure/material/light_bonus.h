/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:16:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTBONUS_H
# define LIGHTBONUS_H

# include "material_bonus.h"
# include "solid_texture_bonus.h"
# include "vec_bonus.h"

typedef struct s_light
{
	t_material	material;
}	t_light;

t_material	*generate_light(t_texture *texture_ptr);

#endif
