/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:16:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 14:36:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "material.h"
# include "vec.h"

typedef struct s_light
{
	t_material	material;
	t_color		emit_color;
}	t_light;

t_light	*gen_light(t_texture *texture_p);

#endif
