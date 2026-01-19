/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:16:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 15:58:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "material.h"
# include "solid_texture.h"
# include "vec.h"

typedef struct s_light
{
	t_material	material;
}	t_light;

t_light	*gen_light(t_texture *texture_p);

#endif
